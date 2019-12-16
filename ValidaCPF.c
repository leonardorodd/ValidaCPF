#include <stdio.h>
#include <locale.h>

int verificaCpf(long long cpf);
int calculaDigitoVerificador(long long cpfValidacao);

int main(){
	
	long long cpf;
	
	setlocale(LC_ALL,"Portuguese");
	printf("Informe o CPF a ser validado: ");
	scanf("%11lld", &cpf);
	
	if(verificaCpf(cpf)==1){
		printf("O CPF %lld é válido",cpf);
	}else{
		printf("O CPF %lld não é válido",cpf);
	}	
		
	return 0;
}

int verificaCpf(long long cpf){

	long long cpfValidacao = cpf/100, i;
	int digitoVerificadorInformado = cpf%100, D1, D2;
	
	for(i=0;i<=99999999999;i+=11111111111){
		if(cpf==i) cpf=0;			
	}
	
	D1=calculaDigitoVerificador(cpfValidacao);
	D2=calculaDigitoVerificador(cpfValidacao*10+D1);		
	
	if(digitoVerificadorInformado==D1*10+D2 && cpf!=0){
		return 1;
	}else{
		return 0;
	}				
}

int calculaDigitoVerificador(long long cpfValidacao){
	
	int multiplicador, somatorio=0, digitoVerificado;
	
	for(multiplicador=2;multiplicador<12;multiplicador++){
		somatorio+=(cpfValidacao%10)*multiplicador;
		cpfValidacao=cpfValidacao/10;
	}
		
	digitoVerificado=11-(somatorio%11);
	
	if(digitoVerificado==10||digitoVerificado==11) digitoVerificado=0;
		
	return digitoVerificado;
}
