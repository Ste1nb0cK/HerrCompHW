pdf.pdf: plotmaker.py pdf1.txt pdf2.txt pdf5.txt
	@echo "#actualizando pdf.pdf"
	@echo "#Creando figura."
	python3 plotmaker.py

pdf1.txt pdf2.txt pdf5.txt: create_txts.sh random_pdf.cpp
	@echo "#actualizando los txts"
	@echo "#Compilando el .cpp"
	g++ random_pdf.cpp
	@echo "#Damos permisos de ejecución a create_txts.sh."
	chmod +x create_txts.sh
	@echo "#Creamos los txts"
	./create_txts.sh


local_clean:
	@echo "#Limpiar de todos los .pdf, .txt y a.out"
	rm *.txt *.pdf a.out
