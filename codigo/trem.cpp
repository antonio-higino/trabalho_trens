#include "trem.h"
#include <QtCore>
#include <pthread.h>

pthread_mutex_t mutex0;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;
pthread_mutex_t mutex4;
pthread_mutex_t mutex5;
pthread_mutex_t mutex6;

pthread_mutex_t mutexd1;
pthread_mutex_t mutexd2;
pthread_mutex_t mutexd3;

//Construtor
Trem::Trem(int ID, int x, int y, int velocidade){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;

    if(ID == 1){
        pthread_mutex_init(&mutex0, NULL);
        pthread_mutex_init(&mutex1, NULL);
        pthread_mutex_init(&mutex2, NULL);
        pthread_mutex_init(&mutex3, NULL);
        pthread_mutex_init(&mutex4, NULL);
        pthread_mutex_init(&mutex5, NULL);
        pthread_mutex_init(&mutex6, NULL);

        pthread_mutex_init(&mutexd1, NULL);
    }
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(velocidade != 200){
                //deadlock 1
                if(x == 310 && y == 30){
                    pthread_mutex_lock(&mutexd1);
                }
                if(x == 310 && y == 150){
                    pthread_mutex_unlock(&mutexd1);
                }
                //-------------

                if(x == 310 && y == 30){
                    pthread_mutex_lock(&mutex0);
                }
                if(x == 310 && y == 150){
                    pthread_mutex_unlock(&mutex0);
                }

                if(x == 330 && y == 130){
                    pthread_mutex_lock(&mutex2);
                }
                if(x == 180 && y == 150){
                    pthread_mutex_unlock(&mutex2);
                }

                if (y == 30 && x <330)
                    x+=10;
                else if (x == 330 && y < 150)
                    y+=10;
                else if (x > 60 && y == 150)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if(velocidade != 200){
                //deadlock 1
                if(x == 490 && y == 150){
                    pthread_mutex_lock(&mutexd1);
                }
                if(x == 330 && y == 130){
                    pthread_mutex_unlock(&mutexd1);
                }
                //-------------

                //deadlock 2
                if(x == 580 && y == 30){
                    pthread_mutex_lock(&mutexd2);
                }
                if(x == 450 && y == 150){
                    pthread_mutex_unlock(&mutexd2);
                }
                //-------------

                if(x == 350 && y == 150){
                    pthread_mutex_lock(&mutex0);
                }
                if(x == 350 && y == 30){
                    pthread_mutex_unlock(&mutex0);
                }

                if(x == 580 && y == 30){
                    pthread_mutex_lock(&mutex1);
                }
                if(x == 580 && y == 150){
                    pthread_mutex_unlock(&mutex1);
                }

                if(x == 490 && y == 150){
                    pthread_mutex_lock(&mutex3);
                }
                if(x == 330 && y == 130){
                    pthread_mutex_unlock(&mutex3);
                }

                if(x == 600 && y == 130){
                    pthread_mutex_lock(&mutex4);
                }
                if(x == 450 && y == 150){
                    pthread_mutex_unlock(&mutex4);
                }

                if (y == 30 && x <600)
                    x+=10;
                else if (x == 600 && y < 150)
                    y+=10;
                else if (x > 330 && y == 150)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:
            if(velocidade != 200){
                //deadlock 3
                if(x == 760 && y == 150){
                    pthread_mutex_lock(&mutexd3);
                }
                if(x == 600 && y == 130){
                    pthread_mutex_unlock(&mutexd3);
                }
                //-------------
                if(x == 620 && y == 150){
                    pthread_mutex_lock(&mutex1);
                }
                if(x == 620 && y == 30){
                    pthread_mutex_unlock(&mutex1);
                }

                if(x == 760 && y == 150){
                    pthread_mutex_lock(&mutex5);
                }
                if(x == 600 && y == 130){
                    pthread_mutex_unlock(&mutex5);
                }

                if (y == 30 && x <870)
                    x+=10;
                else if (x == 870 && y < 150)
                    y+=10;
                else if (x > 600 && y == 150)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4:
            if(velocidade != 200){
                if(x == 200 && y == 170){
                    pthread_mutex_lock(&mutex2);
                }
                if(x == 350 && y == 150){
                    pthread_mutex_unlock(&mutex2);
                }

                if(x == 310 && y == 150){
                    pthread_mutex_lock(&mutex3);
                }
                if(x == 470 && y == 170){
                    pthread_mutex_unlock(&mutex3);
                }

                if(x == 450 && y == 150){
                    pthread_mutex_lock(&mutex6);
                }
                if(x == 450 && y == 270){
                    pthread_mutex_unlock(&mutex6);
                }

                if (y == 150 && x < 470)
                    x+=10;
                else if (x == 470 && y < 270)
                    y+=10;
                else if (x > 200 && y == 270)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 5:
            if(velocidade != 200){
                //deadlock 2
                if(x == 490 && y == 270){
                    pthread_mutex_lock(&mutexd2);
                }
                if(x == 620 && y == 150){
                    pthread_mutex_unlock(&mutexd2);
                }
                //-------------
                //deadlock 3
                if(x == 470 && y == 170){
                    pthread_mutex_lock(&mutexd3);
                }
                if(x == 740 && y == 170){
                    pthread_mutex_unlock(&mutexd3);
                }
                //-------------
                if(x == 470 && y == 170){
                    pthread_mutex_lock(&mutex4);
                }
                if(x == 620 && y == 150){
                    pthread_mutex_unlock(&mutex4);
                }

                if(x == 580 && y == 150){
                    pthread_mutex_lock(&mutex5);
                }
                if(x == 740 && y == 170){
                    pthread_mutex_unlock(&mutex5);
                }

                if(x == 490 && y == 270){
                    pthread_mutex_lock(&mutex6);
                }
                if(x == 490 && y == 150){
                    pthread_mutex_unlock(&mutex6);
                }

                if (y == 150 && x < 740)
                    x+=10;
                else if (x == 740 && y < 270)
                    y+=10;
                else if (x > 470 && y == 270)
                    x-=10;
                else
                    y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::mudarVelocidade(int novaVelocidade){
    this->velocidade = novaVelocidade;
}




