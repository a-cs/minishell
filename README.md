<h1 align="center">Minishell</h1>

<p align="center">
  <img src=./assets/Mi-shell.png alt="Welcome to Mi-Shell"/>
</p>

___
## **Introduction**

Minishell is a project from the 2nd phase of the common core of [42 School](https://www.42sp.org.br/).

The goal of this project was to create a Shell similar to bash, using only C.
___
## **Group Members**

[Anderson Carneiro Sousa](https://github.com/a-cs/)

[Rodrigo Longhi](https://github.com/rodrigolonghi)

___
## **How to start**

*the code has been tested only on Linux

### Clone this repository
```bash
git clone https://github.com/a-cs/minishell.git
cd minishell
```

### Install the readline library
```bash
sudo apt-get install libreadline-dev
```

### Compile
```bash
make
```
### Run
```bash
./minishell
```
___
## **Demo**
[![minishell](./assets/minishell.gif)](https://youtu.be/ClU5JlaS3Vk)
*To watch the video, click on the gif.

___
## **Builtins commands**

commands | <p align="center">description </p> |
---|------|
**echo** | Print the arguments to the standart output. *Accepts the **-n** flag.|
**cd** | Change the shell working directory.|
**pwd** | Print the current working directory.|
**export** | Export variables to shell.| 
**unset** | Delete variable of the shell.|
**env** | Print the environment.| 
**exit** | Exit the shell| 
___
## **Implemented features**
- [x] Execute linux commands
- [x] Handle environment variables and **$?**
- [x] Handle **double quotes**
- [x] Handle **single quotes**
- [x] Handle **redirects**
- [x] Handle **pipes**
- [x] Handle **Crtl + C**, **Crtl + D** and **Crtl + \\** like bash
- [x] **History**
