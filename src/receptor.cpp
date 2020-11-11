#include "camadafisica.h"
#include "camadaenlace.h"

/*************************************************************
* 						Camada Fisica
*************************************************************/

int tamanhoMsgRecepcao; // tamanho da mensagem de entrada
int cont = 0;
string msgRecebida = ""; // armazena resultado da decodificacao

void CamadaFisicaReceptora (vector<int> quadro, int tamanhoMsg) {
  // armazena tamanho da camada fisica transmissora
  	tamanhoMsgRecepcao = tamanhoMsg;
	vector<int> fluxoBrutoDeBits; 

  // alterar de acordo o teste
	int tipoDeDecodificacao = 0; 
  
	switch (tipoDeDecodificacao) {
		case 0 : //codificao binaria
			fluxoBrutoDeBits =
			CamadaFisicaReceptoraDecodificacaoBinaria(quadro);
			break;
		case 1 : //codificacao manchester
			fluxoBrutoDeBits =
			CamadaFisicaReceptoraDecodificacaoManchester(quadro);
			break;
		case 2 : //codificacao manchester diferencial
			fluxoBrutoDeBits =
			CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(quadro);
			break;
	}//fim do switch/case

	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}//fim do metodo CamadaFisicaTransmissora


void CamadaDeAplicacaoReceptora (vector<int> quadro) {
	string mensagem; 
	int valorAscii;	// Armazena o valor decimal na tabela Ascii de cada quadro
	char letra;

  // converte quadro de vetor de inteiros para string
	for (int i = 0; i < 8; i++){
		mensagem += to_string(quadro[i]);
	}
	cout << "Char em Binario Decodificado: "<< mensagem << endl;

  // pega valor decimal da tabela ASCII do string em binario
	valorAscii = stoi(mensagem, 0, 2);
	cout << "Valor ASCII: "<< valorAscii << endl;

  // casting do valor ASCII para char
	letra = (char)valorAscii;
	cout << "Letra: "<< letra << endl;

	msgRecebida += letra;

	AplicacaoReceptora(msgRecebida);
}//fim do metodo CamadaDeAplicacaoReceptora

void AplicacaoReceptora (string mensagem) {
  cont++;
  if(cont == tamanhoMsgRecepcao) {
    cout << "\n\nA mensagem recebida foi: " << mensagem << endl;
  }
}//fim do metodo AplicacaoReceptora 

/*************************************************************
* 						Camada Enlace
*************************************************************/

void CamadaEnlaceDadosReceptora (vector<int> quadro) {
    CamadaEnlaceDadosTransmissoraEnquadramento(quadro);
    //chama proxima camada
    CamadaDeAplicacaoReceptora(quadro);
}//fim do metodo CamadaEnlaceDadosReceptora

void CamadaEnlaceDadosReceptoraEnquadramento (vector<int> quadro) {
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    vector<int> quadroDesenquadrado;
	
    switch (tipoDeEnquadramento) {
        case 0 : //contagem de caracteres
            quadroDesenquadrado =
            CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case 1 : //insercao de bytes
            quadroDesenquadrado =
            CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        case 2 : //insercao de bits
            quadroDesenquadrado =
            CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits(quadro);
}//fim do switch/case
}//fim do metodo CamadaEnlaceDadosReceptoraEnquadramento

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres (vector<int> quadro) {
    //implementacao do algoritmo para DESENQUADRAR
}//fim do metodo CamadaEnlaceDadosReceptoraContagemDeCaracteres

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes (vector<int> quadro) {
    //implementacao do algoritmo para DESENQUADRAR
}//fim do metodo CamadaEnlaceDadosReceptoraInsercaoDeBytes

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits (vector<int> quadro) {
    //implementacao do algoritmo para DESENQUADRAR
}//fim do metodo CamadaEnlaceDadosReceptoraInsercaoDeBits
