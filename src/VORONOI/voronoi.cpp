#include <iostream>
#include <fstream>
#include <cassert>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> DT;
typedef K::Point_2 Point_2;

int main() {
    std::ifstream ifs("plants.dt.cin");
    assert(ifs);

    DT dt;
    Point_2 t;
    while (ifs >> t){
        dt.insert(t);
    }
    ifs.close();

    assert(dt.is_valid());

    std::cout << "Voronoi Faces:" << std::endl;
    for (auto face_it = dt.finite_faces_begin(); face_it != dt.finite_faces_end(); ++face_it){
        std::cout << "Face vertices:";
        for (int i = 0; i < 3; ++i){
            Point_2 vertex = face_it->vertex(i)->point();
            std::cout << " (" << vertex.x() << "," << vertex.y() << ")";
        }
        std::cout << std::endl;
    }

    return 0;
}
