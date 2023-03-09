# git原理

## Branch

<u>一个快照构成的连续的单向链表称作分支，每个分支有一个指向该分支快照的指针</u>

在git中路径也被当做文件夹处理

每次提交会创建一个子版本，子版本来自于上一个父版本

这一系列的版本称为branch/stream。在git中main stream称作HEAD

git branch <branchname> — creates a new branch from the current HEAD (working directory)
git checkout -b <branchname> — creates a new branch from the current HEAD, and switches the working directory to the new branch
git diff <branchname> - <path> — shows the difference of path between the working directory and the given branch
git checkout <branchname> - <path> — checks out files from the given branch into the working directory
git merge <branchname> — merges the given branch into the current branch
git merge -abort — aborts a merge that resulted in conflicts

到了这一步，还没完。如果这时用git log命令查看整个版本历史，你看不到新生成的快照。

$ git log
上面命令没有任何输出，这是为什么呢？快照明明已经写入历史了。

原来git log命令只显示当前分支的变动，虽然我们前面已经提交了快照，但是还没有记录这个快照属于哪个分支。

所谓分支（branch）就是指向某个快照的指针，分支名就是指针名。哈希值是无法记忆的，分支使得用户可以为快照起别名。而且，分支会自动更新，如果当前分支有新的快照，指针就会自动指向它。比如，master 分支就是有一个叫做 master 指针，它指向的快照就是 master 分支的当前快照。

用户可以对任意快照新建指针。比如，新建一个 fix-typo 分支，就是创建一个叫做 fix-typo 的指针，指向某个快照。所以，Git 新建分支特别容易，成本极低。

Git 有一个特殊指针HEAD， 总是指向当前分支的最近一次快照。另外，Git 还提供简写方式，HEAD^指向 HEAD的前一个快照（父节点），HEAD~6则是HEAD之前的第6个快照。

每一个分支指针都是一个文本文件，保存在.git/refs/heads/目录，该文件的内容就是它所指向的快照的二进制对象名（哈希值）。

## Merge

<u>合并拥有同一父节点的分支</u>

![image-20220315112026957](imgs\image-20220315112026957.png)

git merge - abort 

There are changes in both branches, but they conflict. In this case, the conflicting result is left in the working directory for the user to fix and commit, or to abort the merge with git merge –abort.

## Rebase

<u>重定向分支指针</u>

![image-20220315111450866](imgs\image-20220315111450866.png)

git rebase

rebases your current branch onto the tip of the given other branch.

git rebase -i

— interactively rebases.

git cherry-pick

— aborts a cherry-pick that resulted in conflicts.

git revert 

— reverts a patch.

## CherryPick

<u>选一个分支中一个或者几个commit来应用提交到另外一个分支</u>

![image-20220315112009109](imgs\image-20220315112009109.png)

## Revert 

![image-20220315112501885](imgs\image-20220315112501885.png)

# git命令

**初始化**

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

**配置**

````
$ git config --global user.name "用户名" 
$ git config user.email "Email 地址"
$ git config receive.denyCurrentBranch ignore
````

**保存对象和更新缓存区**

```
$ git add --all
```

或者

```
$ git add *
```

**生成快照**

```
$ git commit -m "commit message"
```

**切换快照**

```
$ git checkout {snapchat-hash}
```

**展示某个快照的所有代码改动**

```
$ git show {snapchat-hash}
```

**查看提交历史**

```
git log
```





# git配置



安装 Git

https://www.liaoxuefeng.com/wiki/896043488029600/896067074338496

Android Studio 中 Git的配置及协同开发

https://cloud.tencent.com/developer/article/1739792

git命令行

![image-20220311090415545](imgs\image-20220311090415545.png)

安装UbuntuGUI

tasksel: a utility for installing multiple related packages at once. See the documentation for more details.

slim: A display manager is an application that starts the display server, launches the desktop, and manages user authentication

搭建git服务器

https://zhuanlan.zhihu.com/p/40371444

mkdir COVID-19_Map.git
root@iZt4n2r37at459efgntordZ:/home/git# git init --bare COVID-19_Map.git/
Initialized empty Git repository in /home/git/COVID-19_Map.git/
root@iZt4n2r37at459efgntordZ:/home/git# chown -R git COVID-19_Map.git/



初始化 git 仓库

```bash
git init
```



关联远程仓库

```bash
git remote add origin git@github.com:sony-netapp/SearchApp4China.git
```

# 仓库

3）仓库配置
1、配置全局用户名和邮箱
git config —global user.name “name”
git config —global user.email “email address”
2、配置当前仓库用户名和邮箱
git config user.name “name”
git config user.email “email address”

# 分支

## 本地

查看本地分支

```bash
git branch
```



创建本地分支

```bash
git checkout -b new-local-branch-name
```



拉取远程分支并merge到本地

```bash
git pull origin Amaebi_S_DEV:Amaebi_S_DEV    
```

work/integration-tests/testapp/src/main/java/androidx/work/integration/testapp/ForegroundWorker.kt

删除本地分支

```bash
git branch -d pullrequest_Valhalla2_dev 
```

## 远程

查看所有分支

```bash
git branch -a
```



创建远程分支

```bash
git push origin origin_branch:local_branch
```



查看远程分支的提交

```bash
git log origin/branch-name
git log HEAD...origin/branch-name
```



切换到远程分支

```bash
git checkout -b new-branch-name remote-branch-name
git checkout -b sony/banko/s-develop-01 origin/sony/banko/s-develop-01
```



删除远程分支

```bash
git push origin --delete pullrequest_Valhalla2_dev
```



# 文件

查看修改过的文件

```bash
git status
```



显示可引用的历史版本记录（本地）

```bash
git reflog
```



强制跳转回退到某个版本

```bash
git reset --hard ****
```



找到.gitconfig文件

```bash
git config --list --show-origin
```



添加某个文件到git

```bash
git add file-name
```



添加所有文件到git

```bash
git add .
git add *
```



放弃所有本地修改

```bash
git checkout .
```



删除不在缓存区的文件

```bash
git clean -f #删除文件
git clean -fd #删除文件和目录
git clean -xfd #连 gitignore 的untrack 文件/目录也一起删掉 (慎用,一般这个是用来删掉编译出来的 .o之类的文件用的)  
git clean -nxfd # 在用上述 git clean 前,墙裂建议加上 -n 参数来先看看会删掉哪些文件,防止重要文件被误删
```



# 提交

将本地git记录添加到远程

```bash
git commit -m "modify DownloadUri from PRD to DEV"
```



# 标签

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



# 其他

查看提交记录

```bash
git log
```





# 常见场景及处理

已经修改了分支但还没有add的情况下，切换分支
```
//清空修改
git checkout . 
//切换分支
git checkout branchname
```

同一个电脑上添加两个github仓库

https://blog.csdn.net/qq_34634812/article/details/90168486

windows下启动git bash每次启动自动添加ssh-agent和ssh-add密钥

https://blog.csdn.net/wobofan2006/article/details/126505622
