let totalSlides = document.querySelectorAll('.slider--item').length;
let currentSlide = 0;


document.querySelector('.slider--width').style.width = 
`calc(100vw * ${totalSlides})`;

document.querySelector('.slider--controls').style.height =
`${document.querySelector('.slider').clientHeight}px`;

function goPrev(){
    currentSlide--;
    if(currentSlide<0){
        currentSlide = totalSlides-1;//-1 porque começa do zero
    }
    updateMargin();
}

function goNext(){
    currentSlide++;
    if(currentSlide> (totalSlides-1)){
        currentSlide = 0;//-1 porque começa do zero
    }
    updateMargin();
}

function updateMargin(){//para ajustar a tela para o tamanho da tela do usuário
    let newMargin = (currentSlide * document.body.clientWidth);

    document.querySelector('.slider--width').style.marginLeft=
        `-${newMargin}px`;
}

setInterval(goNext, 3000);