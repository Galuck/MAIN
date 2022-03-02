function menuToggle(){
    let menuArea= document.getElementById("menuArea");

    if(menuArea.classList.contains('menu-opened')==true){
        menuArea.classList.remove('menu-opened');
    }else{
        menuArea.classList.add('menu-opened');
    }

}

let lista = ['Ovo', 'Farinha','Corante', 'Massa'];

let res =lista.toString();//vai fazer a lista virar uma string separada por vírgulas
console.log(res);
res =lista.indexOf('Corante');//vai procurar o índice da palavra em questão
console.log(res);

lista.pop();//isso é literalmente parte de pilha em Estrutura de Dados
lista.shift();//remove o primeiro
lista.push('Carneiro');

//para deletar, não usar o delete, pq ele deixa o slot ali, mas vazio.
lista.splice(1,1);//remover a partir do item 1 + remover 1 itens

listaNum=[45,4,9,16,25];
lista2=listaNum.map(function(item){
    return item * 2;
});
let result =lista2;
console.log(result);

let d = new Date();
console.log(d);// vai mostrar a data e horário detalhadamente
console.log(d.toDateString);//vai mostrar a data mais normal, menos detalhada
d = new Date(2020, 0, 1, 12,30,56);//mês começa em 0, ano mes dia hora minuto segundos
console.log(d);

//Math.floor(Math.random()*100); para mostrar números aleatórios de 0 a 100


function showTime(){
    let d = new Date();
    let h = d.getHours();
    let m = d.getMinutes();
    let s = d.getSeconds();
    let txt = h +':' + m + ':' + s;

    document.querySelector('.demo').innerHTML = txt;

}

let timer = setInterval(showTime,1000);