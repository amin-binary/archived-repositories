## My Online Judge Solutions

- lightoj solutions are in it's own folder (`/lightoj`)
- codeforces contests are on the root `/contest-number-c++14`

## Generating codeforces test files
The repo contains a modifed version of [codeforces-parser](https://github.com/johnathan79717/codeforces-parser) (fixed for OSX).  
First edit the `_template.cc` file to match your needs.  
Then run `./parse.py contest_number (e.g. ./parse.py 513)` to generate templates and test cases for each problem.  

The layout will be like this:

```
984-c++14/
├── A
│   ├── A.cc
│   ├── input1
│   ├── input2
│   ├── output1
│   ├── output2
│   └── test.sh
├── B
│   ├── B.cc
│   ├── input1
│   ├── input2
│   ├── output1
│   ├── output2
│   └── test.sh
...
``` 

Run `./test.sh` to compile and run the test cases.  
