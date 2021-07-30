import numpy as np
import matplotlib.pyplot as plt

arquivo = open("resultado.txt","r")
resultados = arquivo.readlines()
tamanhos_caixa = []
tamanhos_merge = []
tamanhos_bubble = []
tamanhos_insertion = []
caixa = []
bubble = []
merge = []
insertion = []

for r in resultados:
    mod, tam, tempo = r.split(' ')
    if mod == "Caixa":
      tamanhos_caixa.append(tam)
      caixa.append(float(tempo.strip()))
    elif mod == "Bubble":
        tamanhos_bubble.append(tam)
        bubble.append(float(tempo.strip()))
    elif mod == "Merge":
        tamanhos_merge.append(tam)
        merge.append(float(tempo.strip()))
    elif mod == "Insertion":
        tamanhos_insertion.append(tam)
        insertion.append(float(tempo.strip())) 


fig = plt.figure()
ax = fig.add_subplot(111)
fig.set_figheight(25)
fig.set_figwidth(50)


plt.plot(tamanhos_caixa, caixa, label = "caixa")

plt.plot(tamanhos_bubble, bubble,  label = "bubble")

plt.plot(tamanhos_merge, merge, label = "merge")

plt.plot(tamanhos_insertion, insertion, label = "insertion")

ax.xaxis.set_ticks(np.arange(0,213,8))
ax.tick_params(axis='y', which='major', labelsize=30)
ax.tick_params(axis='x', which='major', labelsize=30, rotation=45)

plt.margins(0)
plt.tight_layout()

ax.legend(fontsize=50)
plt.savefig('plt.png')

# plt.xlim(20,150)
# plt.savefig('plt_zoom.png')