// Interface and its implementation
public interface AbstractClass {
    void interfaceMethod();
}

public class ConcreteClass implements AbstractClass {
    private PartClassA partA;
    
    public void interfaceMethod() {
    }
}

// Independent class with its own method
public class IndependentClass {
}

// Base class and its derived class
public class BaseClass {
    private int attribute;

    public void operation1() {
    }

    public void operation2() {
    }
}

public class DerivedClass extends BaseClass {
    private PartClassD objectD;
}

// Class for composition (PartClassD is part of DerivedClass)
public class PartClassD {
}

// Aggregation example
public class WholeClass {
    private PartClassA partA;
}

public class PartClassA {
}

// Sample class with attributes and operations
public class SampleClass {
    private int attribute;
    
    public void operation1() {
    }
    
    public void operation2() {
    }
}