void testPoint3d() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for Point3d" << endl;

    cout << "Print Point3d" << endl;
    cout << "Test print: ";
    Point3d(1, 2.5, 3).print();
    cout << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

void testVector3d() {
    cout << "//////////////////////////////////////////////////////" << endl;
    cout << "Test for Vector3d" << endl << endl;
    
    cout << "Test constructor and print Vector3d" << endl;
    Point3d p1(1.4, 2.5, 3.0);
    Point3d p2(2.1, 5.3, 1.5);
    Vector3d(p1, p2).print();
    cout << endl << endl;

    cout << "Test getPositiveVector3d" << endl;
    Vector3d v1(-2.3, 4, -5.7);
    cout << "Initial vector: ";
    v1.print();
    cout << endl;
    cout << "After applying getPositiveVector3d:";
    v1.getPositiveVector3d().print();
    cout << endl;
    cout << "//////////////////////////////////////////////////////"<< endl;
    cout << endl;
}

void testFunctions() {
    testPoint3d();
    testVector3d();
}