同一个电脑上添加两个github仓库

https://blog.csdn.net/qq_34634812/article/details/90168486



windows下启动git bash每次启动自动添加ssh-agent和ssh-add密钥

https://blog.csdn.net/wobofan2006/article/details/126505622



Git: ‘LF will be replaced by CRLF the next time Git touches it‘ 问题解决与思考

[Git: ‘LF will be replaced by CRLF the next time Git touches it‘ 问题解决与思考-CSDN博客](https://blog.csdn.net/Babylonxun/article/details/126598477)



push 大文件时可能遇到的问题，网络缓存不够

```
## 设置http缓存为1000M（大小可以根据需要自行更改）
git config --global http.postBuffer 1048576000 
## 设置https缓存为1000M
git config --global https.postBuffer 1048576000
```



修改了`.gitignore`文件中的规则，之前的commit有需要忽略的文件，可以清除缓存区后重新提交：

清空缓存区：

```
git rm -r --cached .
```



比较同一分支两个提交之间的差别

https://github.com/sony-netapp/HomeAccount4China/compare/a90579c3f95667aff72cd0f630db42dd72d5ade3...bb95b720cbf7ef2acb7d14c8f816e7bd194c2c54



删除本地不存在于远程的分支

```
git fetch --prune

git branch -vv | grep ': gone]' | awk '{print $1}' | xargs -r git branch -d
```

