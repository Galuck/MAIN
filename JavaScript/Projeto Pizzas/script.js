let modalQt =1;
const cs = (el)=>document.querySelectorAll(el);
const c = (el)=>document.querySelector(el);


pizzaJson.map((item, index)=>{
    let pizzaItem = c('.models .pizza-item').cloneNode(true);
    //preencher as informações em pizza-item

    pizzaItem.setAttribute('data-key', index);//para mostrar no modal a item específica escoljida

    //a ordem vai alterar as coisas no

    pizzaItem.querySelector('.pizza-item--img img').src = item.img;
    pizzaItem.querySelector('.pizza-item--name').innerHTML = item.name;
    pizzaItem.querySelector('.pizza-item--desc').innerHTML = item.description;
    pizzaItem.querySelector('.pizza-item--price').innerHTML = `R$ ${item.price.toFixed(2)}`;
    pizzaItem.querySelector('a').addEventListener('click', (e)=>{
        //bloquear a ação para não atualizar a tela
        e.preventDefault();
        let key = e.target.closest('.pizza-item').getAttribute('data-key');
        modalQt=1;

        console.log(pizzaJson[key]);
        //
        c('.pizzaBig img').src = pizzaJson[key].img;
        c('.pizzaInfo h1').innerHTML = pizzaJson[key].name;
        c('.pizzaInfo--desc').innerHTML = pizzaJson[key].description;
        c('.pizzaInfo--actualPrice').innerHTML = `R$ ${pizzaJson[key].price.toFixed(2)}`;
        c('pizzaInfo--size.selected').classList.remove('selected')
        cs('.pizzaInfo--size').forEach((size, sizeIndex)=>{
            if(sizeIndex==2){
                size.classList.add('selected');
            }
            
            size.querySelector('span').innerHTML = pizzaJson[key].sizes[sizeIndex];
        });

        c('.pizzaInfo--qt').innerHTML=modalQt;

        c('.pizzaWindowArea').style.display = 0;
        c('.pizzaWindowArea').style.display = 'flex';
        setTimeout(()=>{//vai esperar 1/5 segundo
            c('.pizzaWindowArea').style.display = 1;
        },200);
        
    });


    c('.pizza-area').append( pizzaItem );

});