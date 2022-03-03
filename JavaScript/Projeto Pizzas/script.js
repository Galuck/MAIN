const cs = (el)=>document.querySelectorAll(el);
const c = (el)=> {
    return document.querySelector(el);
}

pizzaJson.map((item, index)=>{
    let pizzaItem = c('.models .pizza-item').ckoneNode(true);
    //preencher as informações em pizza-item

    c('.pizza-area').append( pizzaItem );

});