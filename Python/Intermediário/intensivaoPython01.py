import pyautogui
import pyperclip

import time

import sys 

import pandas

time.sleep(2)# ou pyautogui.PAUSE=1

pyautogui.press("win")#tecla do windows
pyautogui.write("opera")
pyautogui.press("enter")

time.sleep(1)


#pyautogui.click()
#pyautogui.write("https://www.youtube.com/channel/UCfqMXtV0-8uVFE6tfrmQTXw"#entra no link # não escreve caracer especial como "?", usar pyperclip
pyperclip.copy("https://www.youtube.com/channel/UCfqMXtV0-8uVFE6tfrmQTXw")
pyautogui.hotkey("ctrl", "v")
pyautogui.press("enter") #para apenas uma tecla
time.sleep(2) #pra dar tempo de pausar meu vídeo 
pyautogui.press("space") #para pausar o vídeo ta página
pyautogui.click(x=613, y=544, clicks=2, interval=0.05)
time.sleep(1)
pyautogui.click(x=743, y=691, clicks=2, interval=0.05)
time.sleep(2.5)
pyautogui.press("space")
pyautogui.click(x=1068, y=972, clicks=2, interval=0.5)


time.sleep(1)


pyautogui.hotkey("ctrl", "t") #vai apertar ctrl + t (combinação de teclas, atalhos)
pyperclip.copy("https://drive.google.com/drive/folders/149xknr9JvrlEnhNWO49zPcw0PW5icxga")#copiou o link na área de transferencia, só dar ctrl v agr
#pyautogui.write()
pyautogui.hotkey("ctrl", "v")
pyautogui.press("enter")

time.sleep(3)
pyautogui.click(x=374, y=341, clicks=2, interval=0.05)#pasta exportar
time.sleep(1.5)
pyautogui.click(x=381, y=340)#selecionar arquivo
time.sleep(0.5)
pyautogui.click(x=1713, y=178)#config do arquivo
time.sleep(0.5)
pyautogui.click(x=1465, y=590)#download

#descobrir a posição de um item para clicar
#ime.sleep(2)
#print(pyautogui.position())

time.sleep(7)#esperar download terminar

#Calcular Indicadores
# PANDAS    Analise de dados

#as pd   pd.nlknmln
                          #r                    #nome arquivo
tabela = pandas.read_excel("D://Downloads OPERA GX/Vendas - Dez.xlsx")#passar nome completo do arquico com caminho (path)
                                                    # , sheets para mudar de aba do arquivo
display(tabela)
                                    #média
faturamento = tabela["Valor Final"].mean() #pegar coluna e fazer a média
quantidade = tabela["Quantidade"].sum()#.sum vai somar
faturamento1 = tabela["Valor Final"].sum()

#calcular faturamento e qtd de produtos
time.sleep(5)

pyautogui.press("win")#agora para escrever o resultado no bloco de notas, poderia ser em qualquer lugar
pyautogui.write("bloco de notas")
time.sleep(0.5)
pyautogui.press("enter")
time.sleep(2)

texto = f"""Bom dia a todos
        A média dos preços de venda do mês é: R${faturamento:,.2f}
        A soma das vendas do mês é: R${faturamento1:,.2f}
        E a quantidade de produtos vendidos foi: {quantidade:,} unidades
    
    Grato, Gabriel May"""

pyperclip.copy(texto)
pyautogui.hotkey("ctrl", "v")
