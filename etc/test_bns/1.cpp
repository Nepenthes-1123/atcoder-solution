#include <bits/stdc++.h>
using namespace std;

//! @brief 三次元空間上の座標表現
struct Float3d {
    float x, y, z;

    Float3d();
    Float3d(float x, float y, float z);
    ~Float3d();

    bool operator==(const Float3d &v) const;

    Float3d operator+(const Float3d &v) const;
    Float3d operator+(const float a) const;
    Float3d operator-(const Float3d &v) const;
    Float3d operator-(const float a) const;
    friend Float3d operator*(float a, const Float3d &v);
    Float3d operator*(const float a) const;
    friend Float3d operator/(float a, const Float3d &v);
    Float3d operator/(const float a) const;
    float dot(const Float3d &v) const;
    Float3d cross(const Float3d &v) const;
};
Float3d::Float3d() {}
Float3d::Float3d(float x, float y, float z) : x(x), y(y), z(z) {}
Float3d::~Float3d() {}

bool Float3d::operator==(const Float3d &v) const {
    return x == v.x and y == v.y and z == v.z;
};

Float3d Float3d::operator+(const Float3d &v) const {
    Float3d ret;
    ret.x = x + v.x;
    ret.y = y + v.y;
    ret.z = z + v.z;

    return ret;
}
Float3d Float3d::operator+(const float a) const {
    Float3d ret;
    ret.x = x + a;
    ret.y = y + a;
    ret.z = z + a;

    return ret;
}

Float3d Float3d::operator-(const Float3d &v) const {
    Float3d ret;
    ret.x = x - v.x;
    ret.y = y - v.y;
    ret.z = z - v.z;

    return ret;
}
Float3d Float3d::operator-(const float a) const {
    Float3d ret;
    ret.x = x - a;
    ret.y = y - a;
    ret.z = z - a;

    return ret;
}

Float3d operator*(float a, const Float3d &v) {
    Float3d ret;
    ret.x = a * v.x;
    ret.y = a * v.y;
    ret.z = a * v.z;

    return ret;
}
Float3d Float3d::operator*(const float a) const {
    Float3d ret;
    ret.x = x * a;
    ret.y = y * a;
    ret.z = z * a;

    return ret;
}

Float3d operator/(float a, const Float3d &v) {
    Float3d ret;
    ret.x = a / v.x;
    ret.y = a / v.y;
    ret.z = a / v.z;

    return ret;
}
Float3d Float3d::operator/(const float a) const {
    Float3d ret;
    ret.x = x / a;
    ret.y = y / a;
    ret.z = z / a;

    return ret;
}

//! @brief 内積
//! @param v
//! @return float
float Float3d::dot(const Float3d &v) const {
    return (x * v.x + y * v.y + z * v.z);
}

//! @brief 外積
//! @param v
//! @return Float3d
Float3d Float3d::cross(const Float3d &v) const {
    return Float3d(y * v.z - v.y * z, -(x * v.z - v.x * z), x * v.y - v.x * y);
}

using Point3d = Float3d;

//! @brief 三次元空間上のベクトル
struct Vec3d : public Float3d {
    using Float3d::Float3d;
    Vec3d(Float3d v);

    float length_squr() const;
    float length() const;
    Vec3d get_norm() const;

    bool is_vertical(const Float3d &v) const;
    bool is_parallel(const Float3d &v) const;
};
Vec3d::Vec3d(Float3d v) : Float3d(v) {}

//! @brief ノルムの自乗を返す
//! @return float
float Vec3d::length_squr() const { return x * x + y * y + z * z; }

//! @brief ノルムを返す
//! @return float
float Vec3d::length() const { return sqrt(this->length_squr()); }

//! @brief 正則化したベクトルを返す
//! @return Vec3d
Vec3d Vec3d::get_norm() const { return Vec3d(x, y, z) / this->length(); }

//! @brief 垂直判定
//! @param v 自身と垂直か判定したいベクトル
//! @return bool
bool Vec3d::is_vertical(const Float3d &v) const { return this->dot(v) == 0; }

//! @brief 平行判定
//! @param v 自身と平行か判定したいベクトル
//! @return bool
bool Vec3d::is_parallel(const Float3d &v) const {
    return this->cross(v) == Float3d(0, 0, 0);
}

//! @brief 三次元空間上の直線
struct Line3d {
    Point3d p;
    Vec3d v;

    Line3d();
    Line3d(const Point3d &p, const Vec3d &v);
    ~Line3d();

    Float3d get_point(float t) const;
};
Line3d::Line3d() {}
//! @brief Construct a new Line 3d:: Line 3d object
//!
//! @param p 始点
//! @param v 方向ベクトル
Line3d::Line3d(const Point3d &p, const Vec3d &v) : p(p), v(v) {}
Line3d::~Line3d() {}

//! @brief 直線上の点を返す
//! @param t 始点pからの距離
//! @return Float3d
Float3d Line3d::get_point(const float t) const { return p + t * v; }

//! @brief 三次元空間上の線分
struct Segment3d : public Line3d {
    using Line3d::Line3d;
    Segment3d(const Point3d &p1, const Point3d &p2);

    Float3d get_end_point() const;
};
//! @brief Construct a new Segment 3d:: Segment 3d object
//!
//! @param p1 端点1
//! @param p2 端点2
Segment3d::Segment3d(const Point3d &p1, const Point3d &p2) {
    p = p1;
    v = p2 - p1;
}

//! @brief 線分の終点を返す
//! @return Float3d
Float3d Segment3d::get_end_point() const { return p + v; }

//! @brief 三次元空間上の平面
struct Plane3d {
    Point3d p;
    Vec3d n;

    Plane3d();
    Plane3d(const Point3d &p, const Vec3d &n);
    ~Plane3d();
};
Plane3d::Plane3d() {}
//! @brief Construct a new Plane 3d:: Plane 3d object
//!
//! @param p 中心点
//! @param n 法線ベクトル
Plane3d::Plane3d(const Point3d &p, const Vec3d &n) : p(p), n(n.get_norm()) {}
Plane3d::~Plane3d() {}

//! @brief 三次元空間上の三角形
class Triangle3d : public Plane3d {
   private:
    Point3d a, b, c;

   public:
    Triangle3d();
    Triangle3d(const Point3d &a, const Point3d &b, const Point3d &c);
    ~Triangle3d();

    Point3d get_circumcenter();
    Vec3d get_radius_vec();
};

Triangle3d::Triangle3d() {}
Triangle3d::Triangle3d(const Point3d &a, const Point3d &b, const Point3d &c)
    : a(a), b(b), c(c) {
    Vec3d vec_ab, vec_ac, vec_ap;
    vec_ab = b - a;
    vec_ac = c - a;

    // 法線ベクトルの取得
    n = vec_ab.cross(vec_ac);
    n = n.get_norm();

    // 円との交点を考えたいので外心を基準点にとる
    float s, t;
    s = (vec_ab.length_squr() * vec_ac.length_squr() -
         vec_ac.length_squr() * vec_ab.dot(vec_ac)) /
        (vec_ab.length_squr() * vec_ac.length_squr() -
         vec_ac.length_squr() * vec_ab.dot(vec_ac)) /
        2;

    t = (vec_ab.length_squr() * vec_ac.length_squr() -
         vec_ab.length_squr() * vec_ab.dot(vec_ac)) /
        (vec_ab.length_squr() * vec_ac.length_squr() -
         vec_ac.length_squr() * vec_ab.dot(vec_ac)) /
        2;

    vec_ap = s * vec_ab + t * vec_ac;

    p = vec_ap + a;
};
Triangle3d::~Triangle3d() {}

Point3d Triangle3d::get_circumcenter() { return p; }
Vec3d Triangle3d::get_radius_vec() { return p - a; }

//! @brief 三次元空間上の球
class Sphere3d {
   protected:
    Point3d p;
    float r;  //! 半径
   public:
    Sphere3d();
    Sphere3d(const Point3d &p, const float r);
    ~Sphere3d();

    Point3d get_center() const;
    float get_radius() const;
};
Sphere3d::Sphere3d() {}
//! @brief Construct a new Sphere 3d:: Sphere 3d object
//!
//! @param p 中心点
//! @param r 半径
Sphere3d::Sphere3d(const Point3d &p, const float r) : p(p), r(r) {}
Sphere3d::~Sphere3d() {}

//! @brief 球の中心点を返す
//! @return Point3d
Point3d Sphere3d::get_center() const { return p; }
//! @brief 球の半径を返す
//! @return float
float Sphere3d::get_radius() const { return r; }

class MoveSphere3d : public Sphere3d {
   private:
    Vec3d v;

   public:
    using Sphere3d::Sphere3d;
    MoveSphere3d(const Point3d &p, const float r, const Vec3d &v);

    void set_vector(const Vec3d &v);
    void move_sphere(const float t);

    void bounce(const Plane3d &pl);
};
MoveSphere3d::MoveSphere3d(const Point3d &p, const float r, const Vec3d &v)
    : v(v) {
    this->p = p;
    this->r = r;
}

//! @brief オブジェクトのベクトルを設定
//!
//! @param v 速さ
void MoveSphere3d::set_vector(const Vec3d &v) { this->v = v; }
//! @brief オブジェクトを時間tだけ、ベクトルに従い移動させる
//!
//! @param t 移動時間
void MoveSphere3d::move_sphere(const float t) { p = p + t * v; }
//! @brief 特定の三次元平面に反射する
//!
//! @param pl 反射する三次元平面
void MoveSphere3d::bounce(const Plane3d &pl) { v = v - 2 * v.dot(pl.n) * pl.n; }

//! @brief 球と球の衝突判定
//! @param s1 球１
//! @param s2 球２
//! @return bool
bool is_collision(const Sphere3d &s1, const Sphere3d &s2) {
    return Vec3d(s2.get_center() - s1.get_center()).length_squr() <=
           pow(s1.get_radius() + s2.get_radius(), 2);
}
//! @brief 球と平面の衝突判定
//!
//! @param s 球
//! @param p 平面
//! @return bool
bool is_collision(const Sphere3d &s, const Plane3d &p) {
    return p.n.dot(s.get_center() - p.p) <= s.get_radius();
}

//! @brief 三次元空間上の円
class Circle3d {
   private:
    Point3d o;
    float r;

   public:
    Circle3d();
    Circle3d(const Point3d &o, const float r);
    ~Circle3d();

    Point3d get_center();
    float get_radius();
};

Circle3d::Circle3d() {}
Circle3d::Circle3d(const Point3d &o, const float r) : o(o), r(r) {};
Circle3d::~Circle3d() {}

Point3d Circle3d::get_center() { return o; }
float Circle3d::get_radius() { return r; }

int main() {
    int n;
    cin >> n;

    int answer = 0;

    vector<Triangle3d> tris(n);

    for (int i = 0; i < n; ++i) {
        Point3d a, b, c;
        cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> c.x >> c.y >> c.z;
        tris.at(i) = Triangle3d(a, b, c);
    }

    Sphere3d s;
    float r, v_x, v_y, v_z;
    cin >> r >> v_x >> v_y >> v_z;
    s = Sphere3d(Point3d(v_x, v_y, v_z), r);

    for (int i = 0; i < n; ++i) {
        Triangle3d t = tris.at(i);

        // nを球の中心,oを円の中心,pを平面上の点とする
        Vec3d np, no;

        np = t.p - s.get_center();
        no = t.n.dot(t.p - s.get_center()) * t.n;

        float l, r;
        if (no.length() == 0) {
            // 三角形の外心と交わるならば衝突しているはず
            l = Vec3d(s.get_center() - t.get_circumcenter()).length();
            r = s.get_radius();

        } else {
            // 三角形と同一平面上の円
            Circle3d c(s.get_center() + no, Vec3d(np.cross(no)).length() /
                                                (np.length() * no.length()));

            // 三角形の外心と交わるならば衝突しているはず
            l = Vec3d(c.get_center() - t.get_circumcenter()).length();
            r = c.get_radius();
        }
        if (l <= r + t.get_radius_vec().length() &&
            l >= r - t.get_radius_vec().length())
            answer++;
    }

    cout << answer << endl;

    return 0;
}
