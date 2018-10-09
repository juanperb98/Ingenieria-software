# Documento de extracción de requisitos
## Partes interesadas
Las partes interesadas en este proyecto consistirán en los profesores que necesitan gestionar deferminada información de sus alumnos correspondientes a un curso en concreto.

## Datos almacenados
Los profesores requieren almacenar los siguientes datos dentro de la aplicación:

  * DNI.
  * Nombre y apellidos.
  * Teléfono.
  * Dirección postal.
  * Curso más alto en que esta matriculado.
  * Fecha de nacimiento.
  * Curso al que pertenece.
  * Indicar si es miebro del grupo al que pertence.

## Requisitos funcionales

  * El sistema tiene que  poder realizar las siguientes acciones para todos los usuarios:
    ..* Registrar un alumno nuevo
    ..* Modificar los datos de un alumno
    ..* Eliminar a un alumno
  * El sistema tiene que  poder mostrar información sobre un usuario en concreto por pantalla.
  * El sisema tiene que poder  mostrar a todos los miembros de un grupo.
  * El sistema tiene que implementar copias de seguridad.
  * El sistema tiene que poder almacenar la información de los alumnos en formato markdown o html.
  * Los alumnos tienen que estar ordenados(tanto ascendente como descendentemente) por:
    ..* Nombre
    ..* Apellidos
    ..* DNI
    ..* Curso más alto en el que esta matriculado
  * Los alumnos podrán ser buscados por Apellidos o DNI.  
  * El sistema tiene que implementar copias de seguridad.

## Requisitos no funcionales
  * Los datos tiene que estar alamacenados en ficheros binarios.
  * El sistema no puede superar los 150 alumnos.
  * El sistema tiene que estar en idioma español.
  * El sistema será diseñado para funcionar en sistemas Linux.
  * En el proceso de registro de un usuario, no pueden existir campos libres, excepto el grupo al que pertenecen.
  * En el caso de encontrar alumnos con el mismo nombre y apellidos se mostrará un menú donde se podrá seleccionar al alumno requerido.
  * Los alumnos no tendrán restricciones de dominio para cualquiera de sus campos.
  * El programa tiene que funcionar sobre sistemas Linux.

## Prioridad de los requisitos
  El sistema de prioridades de nuestros requisitos sigue el siguiente orden:
    1. Creación de alumnos.
    2. Búsqueda de alumnos.
    3. Modificación de los datos de alumnos.
    4. Eliminar alumnos.
    5. Sistema de copias de seguridad.
    6. Exportar información de alumnos.

La elección de este orden de prioridades se considera el más adecuado puesto que la primera acción que tenemos que realizar para poder trabjar con el sistema será introducir alumnos con los que operar (de lo contrario estaremos trabajando sin datos).
Una vez que tenemos la función de introducir alumnos se considera necesario poder buscar dichos alumnos para consultar su información y comprar que ha sido introducida correctamente.
Cuando podamos crear usuarios y buscarlos se contemplan las acciones de *modificar datos de usuarios y eliminar dichos usuarios*. Con esto se pretende poder trabajar con los alumnos previamente introducidos.

Una vez que todo el trabajo con los alumnos este finalizado, se considera necesario implementar el *sistema de copias de seguridad* con un doble objetivo:
  1. Poder guardar la información correcta de los alumnos.
  2. Poder cargar información de alumnos para trabajar con ellos.

Por último para cubrir las funcionalidades requeridas se implementará la exportación de los alumnos en ficheros markdown.
