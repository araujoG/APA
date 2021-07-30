import numpy as np
import matplotlib.pyplot as plt
import sys

arquivo = open(f"{sys.argv[3]}.txt","r")
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

def	dictToArray(dict, tam): 
	vetor = []
	if len(dict[int(sys.argv[2])]) == 0:
		return False
	for i in tam:
		vetor.append(sum(dict[i])/float(len(dict[i])))
	return vetor

for tam in range(int(sys.argv[1]), int(sys.argv[2])+1, 500):
	caixa[tam] = []
	bubble[tam] = []
	merge[tam] = []
	insertion[tam] = []
	tamanhos.append(tam)

for r in resultados:
	mod, tam, tempo = r.split(' ')
	if mod == "Nova":
		iteracao += 1
	elif tempo == '0.000000\n':
		print("tempo zerado")
	elif mod == "Caixa":
		caixa = appendSample(caixa, float(tempo.strip()), int(tam))
	elif mod == "Bubble":
		bubble = appendSample(bubble, float(tempo.strip()), int(tam))
	elif mod == "Merge":
		merge = appendSample(merge, float(tempo.strip()), int(tam))
	elif mod == "Insertion":
		insertion = appendSample(insertion, float(tempo.strip()), int(tam))



print(caixa[106500])
caixa = dictToArray(caixa, tamanhos)
merge = dictToArray(merge, tamanhos)
bubble = dictToArray(bubble, tamanhos)
insertion = dictToArray(insertion, tamanhos)

print(f"plotando com {iteracao} iterações")

fig = plt.figure()
ax = fig.add_subplot(111)
fig.set_figheight(25)
fig.set_figwidth(50)

if caixa:
	plt.plot(tamanhos, caixa, label = "caixa")
if merge:
	plt.plot(tamanhos, merge, label = "merge")
if bubble:
	plt.plot(tamanhos, bubble,  label = "bubble")
if insertion:
	plt.plot(tamanhos, insertion, label = "insertion")

# ax.xaxis.set_ticks(np.arange(0,213,8))
ax.tick_params(axis='y', which='major', labelsize=30)
ax.tick_params(axis='x', which='major', labelsize=30, rotation=45)

plt.margins(0)
plt.tight_layout()

ax.legend(fontsize=50)
plt.savefig('plt_mergeInsertion.png')

# plt.xlim(20,150)
# plt.savefig('plt_zoom.png')