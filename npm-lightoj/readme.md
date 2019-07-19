## Lightoj

-   `npm install -g lightoj`

#### How?

```bash
$ lightoj 1004
username : <type-your-username>
password : ********
opening lightoj.com ...
loging in as <username>
writing templates ...
Done
```

It will generate a folder (`1004/` in our case)

```
$ tree .
1004
├── 1004.cc
├── input1
├── output1
└── test.sh
```

#### To submit do something like

```bash
$ lightoj s1004
opening lightoj.com ...
loging in as <username>
opening submition page ...
Submitting ...
Submitted, view http://lightoj.com/volume_usersubmissions.php
Done
```

#### Build and run tests:

```bash
$ ./1004/test.sh
```
