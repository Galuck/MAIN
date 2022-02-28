function menuToggle(){
    let menuArea= document.getElementById("menuArea");

    if(menuArea.classList.contains('menu-opened')==true){
        menuArea.classList.remove('menu-opened');
    }else{
        menuArea.classList.add('menu-opened');
    }

}