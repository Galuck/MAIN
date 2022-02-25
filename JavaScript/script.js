alert('está funcionando o alerta do navegador');
//window.alert('está funcionando o alerta do navegador');


console.log("a mensagem que eu inserir aqui vai aparecer no console");

// colocar id no html é bem útil para JavaScript
//document.getElementById("titulo").innerHTML="Opa, tudo bem?";
//vai mudar o conteúdo do testo para 
//innerHTML não está funcionando(tem que estar na mesma pasta)

document.getElementById("titulo").innerHTML="Opa, tudo bem?";

//document.write("Algum Texto"); vai sobrescrever a página

//variaveis
var idade = 90;
var nome ="Gabriel";
var x=10;
var y=15;
var total = x + y;

let variavel = 100;//só fica disponível dentro de um escopo específico

if(total>20){
    console.log("Teste de certo");
}

function verde(){
    document.querySelector('#exemplo').classList.remove('azul');
    document.querySelector('#exemplo').classList.remove('vermelho');
    document.querySelector('#exemplo').classList.add('verde');
    //add vai só adicionar, não vai remover, então basicamente só funciona uma vez
}

function vermelho(){
    document.querySelector('#exemplo').classList.remove('verde');
    document.querySelector('#exemplo').classList.remove('azul');
    document.querySelector('#exemplo').classList.add('vermelho');
}

function azul(){
    document.querySelector('#exemplo').classList.remove('verde');
    document.querySelector('#exemplo').classList.remove('vermelho');
    document.querySelector('#exemplo').classList.add('azul');
}

function trocar(){
    if(document.querySelector('button').classList.contains('preto')){
        document.querySelector('button').classList.remove('preto');
        document.querySelector('button').classList.add('verde');
    }else{
        document.querySelector('button').classList.remove('verde');
        document.querySelector('button').classList.add('preto');
    }
}

