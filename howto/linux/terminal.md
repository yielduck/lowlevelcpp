# Путь

Команды, которые описаны ниже, работают с файлами и директориями (папками).  
Для того, чтобы указывать конкретные файлы, нужно уметь составлять ведущий к ним путь.  
Пример пути в win10: **C:\Windows\notepad.exe**  
Путь в unix-like операционной системе: **/usr/bin/g++**  
В каждой директории лежат указатели на текущую и родительскую директории.  
Называются они, соответственно, **.** и **..** (точка и две точки).  
Кроме них, есть такие особые пути, как **/** и **~/**, обозначающие корневые папки системы и пользователя.  
Путь указывается из текущей папки, то есть относительный, если не указано обратное.

* **../dir** -- путь к братской папке dir (да, панчлайн страшный)
* **./dir/file** -- тот же самый путь, что и **dir/file**
* **../../../dir1/dir2/file** -- вот такие крокодилы можно собирать
* **~/.bashrc** -- это путь к конфигурации bash-a
* **/usr/bin** -- здесь лежат всякие исполняемые файлы

Если вы замучаетесь писать длинный путь, нажмите tab -- сработает автодополнение.  
Если оно неоднозначно, можно нажать tab ещё разок.

Некоторые команды могут принимать несколько путей.  
Множества путей можно генерировать с помощью символа *.
* **dir/*** -- все файлы в папке dir
* ***.cpp** -- все файлы в текущей папке, заканчивающиеся на .cpp

Например, пусть в папке dir есть файлы file1 и file2.  
Тогда, **dir/*** --> **dir/file1 dir/file2**.

# Запуск исполняемых файлов
То, что мы называем "командами в терминале", проще воспринимать как исполняемые файлы, вроде **.exe** файлов на винде.  
Если разрешено исполняемый файл запустить, это можно сделать, просто указав путь к нему.  
Например,
> ./a.out

запустит исполняемый файл a.out и выведет результат его работы в терминал.  
Есть специальные папки, например, **/bin/**, **/usr/bin**, в которых происходит поиск исполняемых файлов.  
Если исполняемый файл найдётся сам, то его можно запустить, просто указав его имя:
> pwd

## cd <ins>destination</ins>
cd -> change directory  
По умолчанию, **destination = ~/**.

* cd ..
* cd ../../../mnt/c/stuff
* cd /home/user/proga
* cd ~/.ssh/

## ls <ins>target<ins/>
По умолчанию, **target = .**.  
Выводит список файлов и папок, дочерних указанной.  
Не выведет имена, начинающиеся с точки.    
С этим поможет **ls -a**.

* ls
* ls -a
* ls /home
* ls ~/.ssh

## mkdir <ins>name</ins>*
mkdir -> make a directory

* mkdir test
* mkdir папка мамка
* mkdir пробелы\ это\ иногда\ больно
* mkdir ~/隠し事

## rm [-r] [-f] <ins>target</ins>*
rm -> remove  
Нетрудно догадаться, что эта штука удаляет файлы.  
Папки тоже может вырезать.  
'-r' -> recursive, '-f' -> force

* rm a.out
* rm -f dir/*
* rm -rf /

## mv <ins>source</ins> <ins>target</ins>
mv -> move  
Сменит путь source на target.  
Получается, перемещает и переименовывает.
* mv a.out test
* mv -r dir/ ~/.

## cp [-r] <ins>source</ins> <ins>target</ins>
cp -> copy  
'-r' для рекурсии, если хочется скопировать папку.
* cp file file_copy
* cp -r dir/ dir_copy/

## cat <ins>target</ins>
Выводит содержимое файла.
* cat /dev/urandom