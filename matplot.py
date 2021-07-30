import numpy as np
import matplotlib.pyplot as plt
import sys

arquivo = open("saida.txt","r")
resultados = arquivo.readlines()
tamanhos = []
caixa = {}
bubble = {}
merge = {}
insertion = {}
iteracao = 0

def	appendSample(dict, sample, tam): 
	dict[tam].append(sample)
	return dict

def	dictToArray(dict, tam, index = 0): 
	vetor = []
	for i in tam:
		dict[i].sort()
		vetor.append(dict[i][index])
	return vetor

for tam in range(int(sys.argv[1]), int(sys.argv[2])+1, 500):
	caixa[tam] = []
	bubble[tam] = []
	merge[tam] = []
	insertion[tam] = []
	tamanhos.append(tam)

for r in resultados:
	mod, tam, tempo = r.split(' ')
	if mod == "Caixa":
		caixa = appendSample(caixa, float(tempo.strip()), int(tam))
	elif mod == "Bubble":
		bubble = appendSample(bubble, float(tempo.strip()), int(tam))
	elif mod == "Merge":
		merge = appendSample(merge, float(tempo.strip()), int(tam))
	elif mod == "Insertion":
		insertion = appendSample(insertion, float(tempo.strip()), int(tam))
	elif mod == "Nova":
		iteracao += 1

caixaMin = dictToArray(caixa, tamanhos)
caixaMax = dictToArray(caixa, tamanhos, 9)
bubble = dictToArray(bubble, tamanhos)
merge = dictToArray(merge, tamanhos)
insertion = dictToArray(insertion, tamanhos)

print(f"plotando com {iteracao} iterações")

fig = plt.figure()
ax = fig.add_subplot(111)
fig.set_figheight(25)
fig.set_figwidth(50)

plt.plot(tamanhos, caixaMin, label = "caixaMin")
plt.plot(tamanhos, caixaMax, label = "caixaMax")

# plt.plot(tamanhos, bubble,  label = "bubble")

# plt.plot(tamanhos, merge, label = "merge")

# plt.plot(tamanhos, insertion, label = "insertion")

# ax.xaxis.set_ticks(np.arange(0,213,8))
ax.tick_params(axis='y', which='major', labelsize=30)
ax.tick_params(axis='x', which='major', labelsize=30, rotation=45)

plt.margins(0)
plt.tight_layout()

ax.legend(fontsize=50)
plt.savefig('plt2.png')

# plt.xlim(20,150)
# plt.savefig('plt_zoom.png')