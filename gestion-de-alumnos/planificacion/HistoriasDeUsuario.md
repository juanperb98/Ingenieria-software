alunmo:
	- dni (pk)
	- nombre completo
	- telefono
	- email (sk)(auto-generado)
	- direccion postal
	- curson mas alto
	- fecha nacimiento
	- equipo al que pertenece
	- es lider (0,1) con el grupo
	--
	- busqueda usuario por dni o apellido
	- crud
	--
	- todos los campos son obligatorios a exepcion del grupo	
	- solo una clase
	- si existen dos alumnos en una busqueda, se mostrará un menu para elegirlo
	- menu
	- español
	- sencillo as FUCK
	- si restriciones de dominio
	- copias de seguridad , crud
	- fichero binario como almacenamiento
	- linux based
	- maximo 150 alunmos
	- listado de alumnos ordenado por
		* nombre
		* dni
		* apellidos
		* curso mas alto matriculado
		* de forma ascendiente o descentiente
	- las consultas se podran mostrar por cli o markdown o html
	- los ficheros se guardan y se muestran automaticamente





## añadir alumno
	- como profesor quiero agregar mis almos de forma individial
	- prioridad: 1
### reverso
	- registrar usuario y guardarlo en la base de datos.
	- teniendo en cuenta los requisitos:
		- no se puede repitir el dni
		- el correo electrónico se generará automaticamente
		- La informacion para introducir es obligatoria exceptuando el grupo y si es lider o no
	
## busqueda de alumno
	- como profesor quiero poder buscar entre mis alumnos y mostrarlos en determinados formatos.
	- prioridad: 2
### reverso
	- la busqueda se podra efectuar sobre el dni, apellidos y grupo
	- en el caso de haber varios resultados, se mostrará una lista
	- puede estar ordenada, ascendente o descendentemente por dni y apellidos

## modificar alumno
	- como profesor quiero poder modificar los datos de mis alumnos
	- prioridad: 2
### reverso
	- depende de:
		- busqueda de alumno
	- en el caso de que la busqueda resulte en varios resultados, se mostrara una lista para seleccionar el alumno que se desea modificar


## borrar alumno
	- como profesor, deseopoder borrar alumnos del sistema
	- prioridad: x
### reverso
	- se borrará el alumno en su totalidad del sistema, sin embargo, quedará registrado en las copias de seguridad anteriores
	- depende de:
		- busqueda.

## exportar información de alumno
	- quiero poder exportar los datos de un alumno o serie de alumnos para su posterior consulta.
### reverso
	- la información será guardada en markdown o html y mostrada en el navegador
	- depende de: busqueda de alumno


## importar/exportar copias de seguridad
	- quiero poder realizar y cargar copias de seguridad de los alumnos del sistema
### reverso
	- las copias de seguridad seran guardadas con un nombre identidicador de la fecha en la que se realizó

  
