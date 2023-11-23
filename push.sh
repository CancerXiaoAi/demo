#!/bin/sh
echo -n "" > log
git init >> log
git config --global user.name "cancerai"  >> log
git config --global user.email "cancerai@163.com"  >> log
git remote rm origin  >> log
git remote add origin https://gitee.com/cancerai/demo  >> log
git add .  >> log
git commit -m "file"  >> log
git push origin master:master  | grep * >> log