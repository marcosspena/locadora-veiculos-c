all: saida
	@echo " " 
	@echo "Compilação concluída!!"
	@echo " " 
	 
saida: main.o alterarCliente.o alterarLocadora.o atualizaAvaliacaoCliente.o avaliarLocadora.o cadastraCliente.o cadastraLocadora.o gravarCliente.o gravarLocadora.o gravarNewLogingInfo.o listarClientes.o listarLocadoras.o logAsNormalUser.o logAsRoot.o menuCliente.o menuLog.o menuRoot.o removerCliente.o removerLocadora.o setaCategoria.o tryLogin.o visualizaDadosCliente.o visualizarAvaliacoes.o
	gcc -o saida main.o alterarCliente.o alterarLocadora.o atualizaAvaliacaoCliente.o avaliarLocadora.o cadastraCliente.o cadastraLocadora.o gravarCliente.o gravarLocadora.o gravarNewLogingInfo.o listarClientes.o listarLocadoras.o logAsNormalUser.o logAsRoot.o menuCliente.o menuLog.o menuRoot.o removerCliente.o removerLocadora.o setaCategoria.o tryLogin.o visualizaDadosCliente.o visualizarAvaliacoes.o

main.o: main.c
	gcc -o main.o -c main.c

alterarCliente.o: alterarCliente.c
	gcc -o alterarCliente.o -c alterarCliente.c

alterarLocadora.o: alterarLocadora.c
	gcc -o alterarLocadora.o -c alterarLocadora.c

atualizaAvaliacaoCliente.o: atualizaAvaliacaoCliente.c
	gcc -o atualizaAvaliacaoCliente.o -c atualizaAvaliacaoCliente.c

avaliarLocadora.o: avaliarLocadora.c
	gcc -o avaliarLocadora.o -c avaliarLocadora.c

cadastraCliente.o: cadastraCliente.c
	gcc -o cadastraCliente.o -c cadastraCliente.c

cadastraLocadora.o: cadastraLocadora.c
	gcc -o cadastraLocadora.o -c cadastraLocadora.c

gravarCliente.o: gravarCliente.c
	gcc -o gravarCliente.o -c gravarCliente.c

gravarLocadora.o: gravarLocadora.c
	gcc -o gravarLocadora.o -c gravarLocadora.c

gravarNewLogingInfo.o: gravarNewLogingInfo.c
	gcc -o gravarNewLogingInfo.o -c gravarNewLogingInfo.c

listarClientes.o: listarClientes.c
	gcc -o listarClientes.o -c listarClientes.c

listarLocadoras.o: listarLocadoras.c
	gcc -o listarLocadoras.o -c listarLocadoras.c

logAsNormalUser.o: logAsNormalUser.c
	gcc -o logAsNormalUser.o -c logAsNormalUser.c

logAsRoot.o: logAsRoot.c
	gcc -o logAsRoot.o -c logAsRoot.c

menuCliente.o: menuCliente.c
	gcc -o menuCliente.o -c menuCliente.c

menuLog.o: menuLog.c
	gcc -o menuLog.o -c menuLog.c

menuRoot.o: menuRoot.c
	gcc -o menuRoot.o -c menuRoot.c

removerCliente.o: removerCliente.c
	gcc -o removerCliente.o -c removerCliente.c

removerLocadora.o: removerLocadora.c
	gcc -o removerLocadora.o -c removerLocadora.c

setaCategoria.o: setaCategoria.c
	gcc -o setaCategoria.o -c setaCategoria.c

tryLogin.o: tryLogin.c
	gcc -o tryLogin.o -c tryLogin.c

visualizaDadosCliente.o: visualizaDadosCliente.c
	gcc -o visualizaDadosCliente.o -c visualizaDadosCliente.c

visualizarAvaliacoes.o: visualizarAvaliacoes.c
	gcc -o visualizarAvaliacoes.o -c visualizarAvaliacoes.c

clean: 
	rm -f *.o

execClean:
	rm -f saida

