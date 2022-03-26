#####################IMPORTANTE#################################################
#Para un correcto funcionamiento es necesario que en el remoto estén instalados
#Matplotlib, pandas y numpy, de lo contrario fallará. Una versión futura debería
#instalarlos en caso de que no se encuentren instalados.
#Se recomienda tener habilitado la conexión al remoto mediante una llave pública,
#de lo contrario será necesario introducir la constraseña cada vez que se realice
#una descarga/subida o se envie un comando al remoto.
#Fuente: https://makefiletutorial.com/
#https://iluvatar1.github.io/salafis/#org0bff6a2

#NO DEBEN HABER ESPACIOS EN LA DECLARACIÓN
USER_NAME=
host=
port=
sala=

gamma_vs_n.pdf: data.txt plotmaker.py
	@echo '#Preparandose para crear figura'
	@echo '#Subiendo plotmaker al servidor'
	scp -P ${port} plotmaker.py ${USER_NAME}@${host}:/home/${USER_NAME}
	@echo '#Creando figura. Se imprime el tiempo de creación.'
	ssh -J ${USER_NAME}@${host}:${port} ${USER_NAME}@${sala} -t time python3 plotmaker.py
	@echo '#Descargando figura'
	scp -P ${port} ${USER_NAME}@${host}:/home/${USER_NAME}/$@ $@
	@echo '#Descarga completa. Figura actualizada'

data.txt: prog.cpp
	@echo '#Subir .cpp al servidor'
	scp -P ${port} prog.cpp ${USER_NAME}@${host}:/home/${USER_NAME}
	@echo '#Compilar, correr y escribir. Se imprime el tiempo de ejecución.'
	ssh -J ${USER_NAME}@${host}:${port} ${USER_NAME}@${sala} -t 'g++ prog.cpp; time ./a.out > data.txt'
	@echo '#Descargando data.txt'
	scp -P ${port} ${USER_NAME}@${host}:/home/${USER_NAME}/data.txt data.txt
	@echo '#Descarga completa. Data.txt actualizado'

#limpiar el local de los archivos que se descargan del remoto
local_clean:
	rm data.txt a.out gamma_vs_n.pdf
	@echo '#Local limpiado'
#limpiar el remoto borrando todos los archivos con extensiones que haya en /home/usr
remote_clean:
	ssh -J ${USER_NAME}@${host}:${port} ${USER_NAME}@${sala} -t rm *.*
