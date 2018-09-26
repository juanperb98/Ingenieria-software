# Configuración del entorno GIT

Git tiene ciertos valores por defecto que nos permite comenzar a trabajar después  de la instalación, sin embargo, cuando estamos trabajando en conjunto con otras personas es necesario identificarnos dentro de git, de forma que podamos identificar los commits que estemos realizado. Para ello modificaremos los siguientes parámetros.

## Configuración de usuario

```
    git config --global user.name "Nombre de usuario"
```

```
    git config --global user.email "correo_usuario@gmail.com"
```

Con estos sencillos comandos tenemos configurados tanto nuestro nombre de usuario como nuestro correo electrónico de forma que al subir nuestros cambios al repositorio remoto aparezca nuestro nombre en él.

## Configuración de un editor por defecto

Cuando estamos trabajando con git, es posible que obtengamos dieferentes mensajes de error, dichos mensajes de error serán mostrados en un editor de texto (que por defecto es _vim_), podemos cambiar este editor con el siguiente comando.

```
    git config --global core.editor editorFavorito
```

Algunos de los editores que podemos poner son:
* emacs
* vim
* nano

## Configuración de commits por defecto

En un entorno de trabajo grande, estaremos haciendo una gran cantidad de commits, es posible tener preconfigurado una plantilla para nuestro commit, para ello usaremos:

```
    git config --global commit.template ~/.gitmessage.txt
```

Siendo _~/.gitmessage.txt_ el archivo que contiene la plantilla

