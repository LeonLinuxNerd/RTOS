#!/bin/bash

 git add .
 git commit -m "MARKDOWN"
 git remote rm origin
 git remote add origin git@github.com:LeonLinuxNerd/RTOS.git
 git pull origin master
 git push -u origin master
