# Repo

## 初始化

```
$ git init
```

git init命令只做一件事，就是在项目根目录下创建一个.git子目录，用来保存版本信息。

```
$ ls .git

branches/
config
description
HEAD
hooks/
info/
objects/
refs/
```

## 配置

配置全局用户名和邮箱

```
git config —global user.name “name”
git config —global user.email “email address”
```



配置当前仓库用户名和邮箱

```
git config user.name “name”
git config user.email “email address”
```



找到.gitconfig文件

```
git config --list --show-origin
```



查看远程仓库

```shell
git remote -v
```



关联远程仓库

```bash
git remote add origin git@github.com:sony-netapp/SearchApp4China.git
```



删除远程仓库

```shell
git remote rm <repo-name>
```



# WorkZone

放弃工作区中全部的修改
````
git checkout .
````

放弃工作区中某个文件的修改：

```
git checkout -- filename
```

列出缓存区中文件与上一次提交的区别（新增、更改、删除）

```
git status
```

生成快照

```
git commit -m "commit message"
```

切换快照

```
git checkout {snapchat-hash}
```

展示某个快照的所有代码改动

```
git show {snapchat-hash}
```

查看本地提交历史

```
git log
```

显示可引用的本地历史版本记录

```
git reflog
```

强制跳转回退到某个版本

```
git reset --hard <snapshot-hashcode>
```

添加某个文件到git

```
git add <file-name>
```

添加所有文件到git

```
git add --all
git add .
git add *
```

删除不在缓存区的文件

```
git clean -f #删除文件
git clean -fd #删除文件和目录
git clean -xfd #连 gitignore 的untrack 文件/目录也一起删掉 (慎用,一般这个是用来删掉编译出来的 .o之类的文件用的)  
git clean -nxfd # 在用上述 git clean 前,墙裂建议加上 -n 参数来先看看会删掉哪些文件,防止重要文件被误删
```

将本地git记录添加到远程

```
git commit -m "modify DownloadUri from PRD to DEV"
git commit 后在vim编辑提交说明，shift+zz保存退出
```



# Branch

## 本地

查看本地分支

```bash
git branch
```

在本地创建新分支

```
git branch <local-branch-name> 
```

creates a new branch from the current HEAD, and switches the working directory to the new branch

```
git checkout -b <local-branch-name>
```

拉取远程分支并merge到本地

```
git pull origin <local-branch-name>:<remote-branch-name>
```

删除本地分支

```
git branch -d <local-branch-name> 
```

查看所有分支

```
git branch -a
```

## 远程

创建远程分支

```
git push origin origin_branch:local_branch
```

查看远程分支的提交

```
git log origin/branch-name
git log HEAD...origin/branch-name
```

切换到远程分支

```
git checkout -b new-branch-name remote-branch-name
git checkout -b sony/banko/s-develop-01 origin/sony/banko/s-develop-01
```

删除远程分支

```
git push origin --delete pullrequest_Valhalla2_dev
```

拉取远程仓库最新更新

```
git pull origin
```



# Tag

本地创建

```shell
git tag v0.1
```

本地删除（不会删除远程的标签）

```shell
git tag -d v0.1
```

推送本地标签到远程

```shell
git push origin v0.1
```

一次性推送全部尚未推送到远程的本地标签

```shell
git push origin --tags
```

从远程删除标签

```shell
git push origin :refs/tags/v0.1
```

