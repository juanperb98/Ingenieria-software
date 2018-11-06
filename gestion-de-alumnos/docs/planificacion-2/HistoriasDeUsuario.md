<!--

alumno:
	- dni (pk)
	- nombre completo
	- teléfono
	- email (sk)(auto-generado)
	- dirección postal
	- curso mas alto
	- fecha nacimiento
	- equipo al que pertenece
	- es líder (0,1) con el grupo
	--
	- búsqueda usuario por dni o apellido
	- crud
	--
	- todos los campos son obligatorios a excepción del grupo
	- solo una clase
	- si existen dos alumnos en una búsqueda, se mostrará un menu para elegirlo
	- menu
	- español
	- sencillo as FUCK
	- si restricciones de dominio
	- copias de seguridad , crud
	- fichero binario como almacenamiento
	- linux based
	- máximo 150 alumnos
	- listado de alumnos ordenado por
		* nombre
		* dni
		* apellidos
		* curso mas alto matriculado
		* de forma ascendiente o descendiente
	- las consultas se podrán mostrar por cli o markdown o html
	- los ficheros se guardan y se muestran automáticamente
	
-->





## añadir alumno
	- como profesor quiero agregar mis almos de forma individual
	- prioridad: 1
### reverso
	- registrar usuario y guardarlo en la base de datos.
	- teniendo en cuenta los requisitos:
		- no se puede repetir el dni
		- el correo electrónico se generará automáticamente
		- La información para introducir es obligatoria exceptuando el grupo y si es líder o no
	
## búsqueda de alumno
	- como profesor quiero poder buscar entre mis alumnos y mostrarlos en determinados formatos.
	- prioridad: 2
### reverso
	- la búsqueda se podrá efectuar sobre el dni, apellidos y grupo
	- en el caso de haber varios resultados, se mostrará una lista
	- puede estar ordenada, ascendente o descendientemente por dni y apellidos

## modificar alumno
	- como profesor quiero poder modificar los datos de mis alumnos
	- prioridad: 2
### reverso
	- depende de:
		- búsqueda de alumno
	- en el caso de que la búsqueda resulte en varios resultados, se mostrara una lista para seleccionar el alumno que se desea modificar


## borrar alumno
	- como profesor, deseo poder borrar alumnos del sistema
	- prioridad: x
### reverso
	- se borrará el alumno en su totalidad del sistema, sin embargo, quedará registrado en las copias de seguridad anteriores
	- depende de:
		- búsqueda.

## exportar información de alumno
	- como profesor quiero poder exportar los datos de un alumno o serie de alumnos para su posterior consulta.
### reverso
	- la información será guardada en markdown o html y mostrada en el navegador
	- depende de: búsqueda de alumno


## exportar copias de seguridad
	- como coordinador quiero poder realizar copias de seguridad de los alumnos del sistema
### reverso
	- las copias de seguridad serán guardadas con un nombre identificador de la fecha en la que se realizó


## importar copias de seguridad
	- como coordinador quiero poder realizar y cargar copias de seguridad de los alumnos del sistema
### reverso
	- las copias de seguridad serán cargadas sobreescribiendo datos actuales.