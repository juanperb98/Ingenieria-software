# Ramas
## ¿Qué son las ramas?
Es la forma para separar la lı́nea actual de desarrollo con respecto a la principal. Normalmente representan versiones del software que posteriormente son integradas a la lı́nea principal.

![](img/branches.png)  

## ¿Cómo me puedo aprovechar de ellas?
Cuando vamos a trabajar en una nueva funcionalidad, es conveniente hacerlo en una nueva rama, para no modificar la rama principal y dejarla inestable.

### Vamos a crear una rama.

!!! info
	Si usamos git branch sin ningún argumento, nos devolverá la lista de ramas disponibles.
	
Una vez hemos comprobado que no existe una rama 'test' podemos proceder a su creacion.

	$ git chechout -b hola
	Switched to branch 'hola'

<!-- TODO: match the previous file and modify it -->

### Modificamos la nueva rama.
para esto añadiremos un simple hola mundo en SH, creamos un documento nuevo, llamado "HelloWorld.sh" en el cual escribiremos:

	#!/bin/sh
	printf "hello, world\n"

### Salvamos las modificaciones a la rama.
	$ git add HelloWorld.sh
	$ git commit -m "Añadido script hola mundo"
	[hola daae9ca] Añadido script hola mundo
	1 file changed, 3 insertions(+)
	create mode 100644 HelloWorld.sh

### Merge al master.
Una vez provado el nuevo cambio, vemos que no da errores, entonces decidimos implementarlo al master, para ello, nos iremos al master:

	$ git checkout master 

y haremnos mergin desde la rama hola, a la rama master.

	$ git merge hola
	Updating daae9ca..787590a
	Fast-forward
	HelloWorld.sh | 2 +-
	1 file changed, 1 insertion(+), 1 deletion(-)
