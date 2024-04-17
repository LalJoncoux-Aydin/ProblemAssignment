# ProblemAssignment

## Assignment 1
### Instructions
Reverse each word in the input string.\
The order of the words will be unchanged.\
A word is made up of letters and/or numbers.\
Other characters (spaces, punctuation) will not be reversed.

### Build
```g++ -o main_exec_3 main3.cpp```
### Run
```./main_exec_3```
### Variations
main1.cpp - Runtime: 16ms\
main2.cpp (Not sure if the character ' could be considered as part of the word typically in words like "let's go" so this variation handle this case)\
main3.cpp - Runtime: 12ms **BEST**


## Assignment 2
### Instructions
**Refactor code**
Not timed (good to get it back within 24 hours)\
<br>
An intern has provided the code below to update the version number within two different files.\
The intern has left and you need to review and improve the code before submitting to source control.\
<br>
Please do not be constrained by the existing code (i.e. you don't have to keep the same function names, structure)\
Aim for production quality 'best-practice/clean' code

**Original Requirements**
---------------------
A script in a build process needs to update the build version number in 2 locations.\
- The version number will be in an environment variable "BuildNum"
- The files to be modified will be under "$SourcePath/develop/global/src" directory
- The "SConstruct" file has a line "point=123," (where 123 (just an example) should be updated with the value of "BuildNum" Environment variable)
- The "VERSION"file has a line "ADLMSDK_VERSION_POINT= 123" (where 123 (just an example) should be updated with the value of "BuildNum" Environment variable)

### Run
```python3 main1.py```
### Variations
main1.py - Keeps one single backup file and deletes it at every run of the script\
main2.py - Log rotation, log files are generated with datestamp and not deleted on run