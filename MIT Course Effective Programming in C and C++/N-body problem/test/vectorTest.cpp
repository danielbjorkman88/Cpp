#include <nbody/Vector3.h>
#include <gtest/gtest.h>

TEST( vectorTest, dotProduct ) {
  auto v = Vector3f{ 1, 0, 0 };
  auto v_perp = Vector3f{ 0, 1, -1 };

  ASSERT_FLOAT_EQ( dot( v, v_perp ) , 0.0f );
}

TEST( vectorTest, crossProduct ) {
  auto v = Vector3f{ 1, 2, 3 };
  auto i = Vector3f{ 1, 0, 0 };
  auto j = Vector3f{ 0, 1, 0 };
  auto k = Vector3f{ 0, 0, 1 };
  ASSERT_FLOAT_EQ( cross( v, v ).norm(), 0.0f );
  ASSERT_FLOAT_EQ( ( cross( i, j ) - k ).norm(), 0.0f );
  ASSERT_FLOAT_EQ( ( cross( j, k ) - i ).norm(), 0.0f );
  ASSERT_FLOAT_EQ( ( cross( k, i ) - j ).norm(), 0.0f );
}

TEST( vectorTest, setValues ) {
  auto v = Vector3f{ 1, 2, 3 };
  auto i = Vector3f{ 1, 0, 0 };
  v.setX(0.4f);
  i.setY(-0.34f);
  v.setZ(-v.z());
  ASSERT_FLOAT_EQ( v.x(), 0.4f );
  ASSERT_FLOAT_EQ( i.y(), -0.34f );
  ASSERT_FLOAT_EQ( v.z(), -3 );
}
