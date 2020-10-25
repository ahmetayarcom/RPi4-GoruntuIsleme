// Kullanılacak kütüphaneler ve isim uzayları eklendi 
#include <QCoreApplication>
#include <dlib/gui_widgets.h>
#include <dlib/image_transforms.h>
#include <cmath>

using namespace dlib;
using namespace std;

int main(int argc, char *argv[])
{
        std::vector<perspective_window::overlay_dot> points;
        dlib::rand rnd;
        for (double i = 0; i < 20; i+=0.001)
        {
            // Spiral üzerinde bir nokta alınması
            dlib::vector<double> val(sin(i),cos(i),i/4);

            // Noktaya gürültü ekleme
            dlib::vector<double> temp(rnd.get_random_gaussian(),
                                      rnd.get_random_gaussian(),
                                      rnd.get_random_gaussian());
            val += temp/20;

            // Spiralde ne kadar ilerlendiğine göre bir renk seçildi
            rgb_pixel color = colormap_jet(i,0,20);

            // Görüntülenecek noktalar listesine nokta ekleme
            points.push_back(perspective_window::overlay_dot(val, color));
        }
        // Bulut görüntülendi
        perspective_window win;
        win.set_title("3D nokta bulutu penceresi");
        win.add_overlay(points);
        win.wait_until_closed();

    QCoreApplication a(argc, argv);
    return a.exec();
}
