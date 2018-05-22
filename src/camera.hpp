#ifndef CAMERA_H
#define CAMERA_H

#include <QTimer>
#include <QLabel>
#include <queue>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

class CasseBriques;

/* Cette classe permet la gestion de la webcam pour le déplacement du
 * palet avec le mouvement de la main. Elle permet de créer une caméra,
 * de prendre des captures, de l'arrêter temporairement, et de détrerminer
 * une translation en fonction du mouvement de la main */

class Camera : public QLabel
{
    Q_OBJECT

public:

    /*******************************/
    /* Constructeur et destructeur */
    /*******************************/

    /* Pas besoin de passer le jeu (CasseBriques) en paramètre, c'est ce
     * dernier qui récupèrera la valeur de la translation à 'aide d'un get */
    Camera();
    ~Camera();

    /* Permet de créer la caméra, de créer le rectangle dans lequel on récupèrera
     * la translation, et d'initialiser les variables nécessaires au fonctionnement */
    void initialiserCamera();

    /* Méthodes qui permettent de mettre en pause la caméra. La cadence des prises
     * de vues est déterminée par un timer m_timerCam, d'où la nécessité
     * de ces méthodes */
    void stop();
    void start();

    /* Permet d'effectuer une prise de vue, et de calculer la translation de la main.
     * Pour cette dernière, on réeffectue à chaque prise de vue une moyenne des 20
     * dernières translations calculées (à l'aide d'une std::queue) pour "lisser" le
     * déplacement du palet. Cette moyenne est ensuite stockée et récupérée par le
     * jeu pour faire bouger le palet. */
    void capturerImage();

    /* Fonctions qui permettent de définir ou de récupérer l'état d'activité de la
     * webcam (si elle est cochée dans les paramètres ou pas, par exemple) */
    bool getActive() const {return m_active;}
    void setActive(const bool active);

    /* Récupèrer la translation calculée avec capturerImage(). On divise
     * ici par 20 pour obtenir la moyenne des 20 dernières translations
     * (cf la méthode capturerImage) */
    float getTranslation() const {return m_translation/20.0f;}

private:

    bool m_active; // Indique l'état d'activité de la caméra
    QTimer m_timerCam; // Cadence des prises de vues
    std::queue<float> m_buffer; // Stocke les translations consécutives de la MAIN
    float m_translation; // Stocke la translation du PALET

    /* Attributs qui permettent de créer la fenêtre de la webcam, et de
     * dessiner le rectangle vert apparaîssant dessus. */
    cv::VideoCapture cap;
    cv::Mat frame1, frame2, frameRect1, frameRect2;
    cv::Mat resultImage;
    cv::Rect workingRect;
    cv::Rect templateRect;
    cv::Point workingCenter;
};

#endif // CAMERA_H
