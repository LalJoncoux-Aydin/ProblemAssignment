import os
import shutil
import re
import fileinput
import sys

# SCONSTRUCT file interesting lines
# config.version = Version(
# major=15,
# minor=0,
# point=6,
# patch=0
#)
# VERSION file interesting line
# ADLMSDK_VERSION_POINT=6


def backup_file(source_path):
    """Delete previous backup file and create a new one based on the current one"""
    backup_path = source_path + "_bkp"

    # Remove existing backup
    if os.path.exists(backup_path):
        try:
            os.chmod(backup_path, 0o755)
            os.remove(backup_path)
        except PermissionError:
            print(f"Permission denied: Cannot modify {backup_path}.")
            sys.exit(1)   

    # Create a new backup
    try:
        shutil.copy2(source_path, backup_path)  # copy2() to preserve timestamp and permission
        print(f"Backup successfully created at {backup_path}.")

    except PermissionError:
        print(f"Permission denied: Cannot modify {source_path}.")
        sys.exit(1)
    except FileNotFoundError:
        print(f"Error: The file at source path {source_path} does not exist.")
        sys.exit(1)
    except Exception as e:
        print(f"Error copying source file to backup path: {e}")
        sys.exit(1)


def update_config_file(source_path, key, new_value):
    """Update the key in the source path file with the new value in parameter"""
    regex_pattern = fr"{key}=[\d]+"
    new_line = f"{key}={new_value}"

    try:
        for line in fileinput.input(source_path, inplace=True): #inplace=True redirects stdout to the file | read and rewrite in the file
            line = re.sub(regex_pattern, new_line, line)
            sys.stdout.write(line)

    except Exception as e:
        print(f"Error updating key {key} in file at {source_path} : {e}")
        shutil.copy2(source_path + "_bkp", source_path)  # Restore from backup # copy2() to preserve timestamp and permission
        sys.exit(1)

    print(f"Following key:{key} modified with value:{new_value} at:{source_path}.\n")

def main():
    try:
        path = os.path.join(os.environ["SourcePath"], "develop", "global", "src")
        build_nb = os.environ['BuildNum']
    except KeyError:
        print(f"Warning: Environment variable missing")
        sys.exit(1)

    # Add .txt for WSL
    config_files = {
        "SConstruct": "point",
        "VERSION": "ADLMSDK_VERSION_POINT"
    }

    for file, key in config_files.items():
        source_path = os.path.join(path, file)

        try:
            # Grant permission
            os.chmod(source_path, 0o755)
        except Exception as e:
            print(f"Error updating permission on file at {source_path} : {e}")
            sys.exit(1)

        # Delete old and create new backup
        backup_file(source_path)

        # Modify the key in the file
        update_config_file(source_path, key, build_nb)

if __name__ == "__main__":
    main()