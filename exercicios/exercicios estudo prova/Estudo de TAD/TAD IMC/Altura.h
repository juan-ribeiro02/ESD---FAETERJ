typedef struct altura tAltura;

tAltura * altura_cria(float cm, float m);

void altura_libera(tAltura *altura);

void altura_acessa(tAltura *altura, float *cm, float *m);

void altura_atribui(tAltura *altura, float cm, float m);

void altura_exibe(tAltura *altura);

char * altura_get(tAltura *altura);

int altura_compara(tAltura *altura1, tAltura *altura2);

tAltura * altura_soma(tAltura *altura, float cm);

tAltura * altura_copia(tAltura *altura);