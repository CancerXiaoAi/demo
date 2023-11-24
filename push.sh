#!/bin/sh
echo -n "" > log
git init >> log
echo "" >> log
git config --global user.name "cancerai"  >> log
echo "" >> log
git config --global user.email "cancerai@163.com"  >> log
echo "" >> log
git remote rm origin  >> log
echo "" >> log
git remote add origin https://gitee.com/cancerai/demo  >> log
echo "" >> log
git add .  >> log
echo "" >> log
git commit -m "file"  >> log
echo "" >> log
git push origin master:master >> log