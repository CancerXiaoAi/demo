#!/bin/sh
git config --global user.name "cancerai"
git config --global user.email "cancerai@163.com"
git remote rm origin
git remote add origin https://gitee.com/cancerai/demo
git add .
git commit -m "file"
git push origin master:master