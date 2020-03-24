#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <typeinfo>
#include <cmath>

using namespace cv;
using namespace std;




int mascara_derivada_central( Mat *imagem_original, int i, int j )
{

    int resultado_horizontal = abs((static_cast<int>(imagem_original->at<uchar>(i+1,j))/2) - (static_cast<int>(imagem_original->at<uchar>(i-1,j))/2));
    int resultado_vertical = abs((static_cast<int>(imagem_original->at<uchar>(i,j+1))/2) - (static_cast<int>(imagem_original->at<uchar>(i,j-1))/2));

    return resultado_horizontal + resultado_vertical;
}


int main( int argc, char** argv )
{

    // Verificamos se o usuário executou o programa como program.out PATH_PARA_A_IMAGEM.jgp
    if( argc != 2)
    {
     cout <<"Por favor, especifique como argumento o caminho para a imagem desejada." << endl;
     return -1;
    }


    Mat imagem_original;
    imagem_original = imread(argv[1], IMREAD_GRAYSCALE);


    // Caso a imagem que foi enviada como argumento não seja encontrada
    if(! imagem_original.data )                             
    {
        cout << "Não foi possível abrir a imagem requisitada. Certifique-se que o caminho para ela, seu nome e sua extensão estão corretos." << std::endl ;
        return -1;
    }

    // Prosseguimos agora que temos tudo para trabalhar

    // Criamos a matriz que vai comportar a imagem ampliada em 2 pixels na horizontal e vertical
    Mat imagem_ampliada = Mat::zeros(Size(imagem_original.cols+2,imagem_original.rows+2),CV_8UC1);

    // Copiamos a nossa imagem original para a nossa matriz ampliada

    // Usamos i e j variando de 1 até limite - 1 para copiar apenas os pixels referentes a imagem original
    // E colá-los na posição correta da matriz ampliada
    for(int i = 1; i < imagem_original.rows-1; i++)
    {
        for(int j = 1; j < imagem_original.cols-1; j++)
        {
            // Fazemos a cópia do pixel aqui
            imagem_ampliada.at<uchar>(i,j) = imagem_original.at<uchar>(i,j);
        }
    }

    
    // Criamos uma matriz branca (de zeros) com as mesmas dimensoes da nossa matriz ampliada
    // Essa matriz será a nossa imagem com o filtro aplicado
    Mat imagem_final = Mat::zeros(Size(imagem_ampliada.cols,imagem_ampliada.rows),CV_8UC1);


    // Percorremos a nossa matriz da imagem ampliada
    for(int i=1; i<imagem_ampliada.rows-1; i++)
        for(int j=1; j<imagem_ampliada.cols-1; j++)
        {
            // Aplicamos o filtro e ajustamos o valor na nossa matriz final da imagem filtrada
            imagem_final.at<uchar>(i,j) = mascara_derivada_central(&imagem_ampliada, i, j);
        }
            
            

    // Criamos uma janela para mostrar a foto original em escala de cinza
    namedWindow( "Imagem Original (Escala de Cinza)", WINDOW_AUTOSIZE );

    // Mostramos a foto em escala de cinza na janela 
    imshow( "Imagem Original (Escala de Cinza)", imagem_original );


    // Criamos uma janela para mostrar a foto com o filtro aplicado
    namedWindow( "Imagem com Filtro", WINDOW_AUTOSIZE );

    // Mostramos a foto com o filtro aplicado na janela
    imshow( "Imagem com Filtro", imagem_final );


    // Esperamos uma tecla ser pressionada para encerramos o programa
    waitKey(0);
    return 0;
}