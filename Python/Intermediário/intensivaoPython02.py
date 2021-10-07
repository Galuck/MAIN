#Passo 1: importar a base de dados
import pandas
import pyautogui
import pyperclip
import time

time.sleep(2)
pyautogui.hotkey("ctrl", "t")
time.sleep(0.5)
pyperclip.copy("https://drive.google.com/drive/folders/1T7D0BlWkNuy_MDpUHuBG44kT80EmRYIs")
pyautogui.hotkey("ctrl", "v")
pyautogui.press("enter")
time.sleep(3)
pyautogui.click(x=422, y=481)
time.sleep(1)
pyautogui.click(x=1720, y=194)
time.sleep(0.5)
pyautogui.click(x=1460, y=589)
    
time.sleep(7)
                
tabela= pandas.read_csv("D://Downloads OPERA GX/telecom_users.csv")



#Passo 2: vizualizar a base de dados
print(tabela)
#excluir cagadas
tabela= tabela.drop("Unnamed: 0", axis=1)#0 linha / 1 coluna
#tirar valores inuteis ou vazios



#Passo 3: tratamento de dados
print(tabela.info())
#    valores sendo recebidos de forma errada
tabela["TotalGasto"]= pandas.to_numeric(tabela["TotalGasto"], errors= "coerce")#coerce apaga erros
                    #vai converter para int o valor q estava sendo reconhecido como texto
#    valores vazios
#deletar colunas vazias
tabela = tabela.dropna(how="all",axis=1)# 0= linhas 1=colunas/ how = all ou any
#deletar linhas vazias
tabela = tabela.dropna(how="any",axis=0)# 0= linhas 1=colunas/ how = all ou any

print(tabela.info())



#Passo 4: Análise Inicial
tabela["Churn"].value_counts()#vai contar a qtd de cancelamentos
tabela["Churn"].value_counts(normalize=True).map("{:.1%}".format)#numero vai sair dividido por 100
                                            #para formatar em %




#Passo 5: Anaálise mais completa (comparar cada coluna da minha tabela com a coluna de cancelamento)
import plotly.express as px #ferramenta de gráficos

#etapa 1: criar gráfico
for coluna in tabela.columns:#para cada coluna na tabela   # https://plotly.com/python/historiograms/
    grafico=px.histogram(tabela, x=coluna, color= "Churn", color_discrete_sequence=["green","red"])
        #histograma cria o eixo y sozinho
    #etapa 2: exibir gráfico
    print(coluna)
    grafico.show()

#no VSCODE, vai abrir uma porrada de link(mas funciona), já no jupyter, abre tudo na guia em si