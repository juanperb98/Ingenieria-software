# Github

## ¿Qué es github?

Git es un control de versiones que nos permite trabajar comodamente con múltiples versiones de nuestro código, sin embargo, cuando estamos trabajando en el mundo normal, lo general es estar colaborando con otras personas en el mismo proycto. Esta funcionalidad se realiza de forma más cómoda mediante Github.

**Github es un proyecto independiente a git**

Debemos tener clara la anterior afirmación, puesto que Github simplemente es un repositorio donde podemos encontrar múltiples proyectos cuyo control de versiones es _git_, es una plataforma muy útil de usar para la comunicación entre los diferentes equipos.

Antes de continuar será neceseario obtener nuestra cuenta de [Github](https://www.github.com)

<center> <img src="img/github.gif"> </center>

## Sincronización de Github y Git

Cuando estamos trabajando con git estamos haciendo repositorios locales, dichos repositorios estan alojados en nuestro equipo aislados del resto del mundo. Al querer trabajar con Github, será necesario sincronizar los cambios que hagamos en local con los cambios en remoto (dentro de nuestro repositorio Github) para ello tenemos dos opciones de trabajar:

* Autenticación mediante HTTP
* Utilizar claves SSH

### Autenticación HTTP

Consiste en introducir nuestro usuario y contraseña en el caso de que queramos realizar operaciones en remoto ( como pueden ser obtener los cambios o subir nuevos cambios), para ello simplemente tenemos que configurar nuestra cuenta de Github.

En el caso de estar trabajando con claves HTTP, para ahorrar tiempo podemos introducir la contraseña en caché de forma que no la requiera cada vez que tengamos que realizar operaciones remotas, para ello es necesario activar la caché mediante el siguiente comando:
```
    git config --global credential.helper 'cache --timeout=3600'
```

### Autenticación con SSH

Github tiene una opción muy útil que consiste en poder sincronizar las claves [ssh](https://en.wikipedia.org/wiki/Ssh) con Github de forma que podamos realizar cambios sin necesidad de introducir nuestro usuario y contraseña de Github.

Si queremos configurar nuestra clave ssh dentro del repositorio de Github, necesitaremos generarla, para ello introduciremos el siguiente comando en la terminal.

```ssh-keygen -b 4096 ```

De forma que por defecto (aunque podemos cambiarlo dentro del asistente de generación) se guardarán los archivos __id_rsa__ y __id_rsa.pub__ dentro de la carpeta __~/.ssh__ de nuestro usuario, puediendo así copiar el contenido del **último archivo** a la configuración de nuestro perfil de Github:

<center> <img src="img/github-keys.png"> </center>


## Convertir un repositorio en remoto

Como se ha mencionado con anterioridad, cuando estamos trabajando con git lo estamos haciendo de forma local, sin embargo cuando queremos sincronizar dichos cambios con Github, simplemente tenemos que indicarle a git a que repositorio de git tiene que enviarlo, para ello tenemos que ejecutar el siguiente comando:

```
    git  remote  add  origin  url
```

**Tenemos que tener en cuenta que la url, será http si estamos trabajando con este método de autenticación o ssh en el caso de tener configurada la clave pública, ambas opciones nos la facilita Github cuando creamos un nuevo repositorio**

## Clonar un repositorio

Al hablar de Github mencionamos que existían múltiples repositorios creados por numerosas personas, todos usando el _git_ como control de versiones. _¿Qué pasa si quiero obtener el repositorio de una persona?_ Esta pregunta muy frecuente podemos solucionarla con la opción _clone_ de git.

Esta opción nos permite obtener le repositorio (con todos los cambios que se han realizado) sobre cualquier proyecto **público** de Github. Un aspecto a tener en cuenta es que esta operación es que si constamos como colaborador en dicho proyecto podemos realizar todas las operaciones (puesto que se obtienen la configuración del mismo)

Para clonar un repositorio cualquiera simplemente tenemos que ejecutar:

```
    git clone url
```

## Ver repostorios remotos

Cuando estamos trabajando en un proyecto, generalmente subimos todos los cambios a un solo repositorio de Github, sin embargo, es posible que estemos trabajando en diferentes repositorios por diversos motivos. Uno de estos motivos puede ser que estemos obteniendo el código de un repositorio determinado y subiendo nuestros cambios a uno propio.

Para poder llevar el control de los repositorio remotos asociados a nuestro repositorio local, utilizamos el siguiente comando:

```
    git remote -v
```

Si queremos eliminar cualquier repositorio remoto de nuestro repositorio local simplemente podemos borrar el reositiorio haciendo uso del comando

```
  git remote rm origin
```

## Obteniendo y aplicando datos en un repositorio remoto

Cuando hemos terminado de trabajar en nuestro repositorio local, realizados todos nuestros _commits_ y agregados los archivos pertinentes, pasaremos a aplicar los cambios en el repositorio remoto, para ello usaremos el siguiente comando:

```
  git push -u origin master
```
Teniendo en cuenta que _origin_ hará referencia al repositorio remoto con el que estamos trabajando, mientras que _master_ hace referencia a la rama en la que estamos trabajando en nuestro repositorio local.

Para **obtener los cambios** realizados por nosotros (u otras personas) en el repositorio remoto utilizamos:

```
  git pull origin master
```

Haciendo referencia de nuevo a _master_ como la rama en la que queremos obtener los cambios.

**Debemos tener en cuenta que antes de realizar cualquier _git push_ es recomendable hacer un _git pull_ para evitar posibles errores a la hora de subir los cambios al repositorio remoto**
