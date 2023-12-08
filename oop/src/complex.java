public class complex {
    int real, img;

    complex(int r, int i){
        this.real=r;
        this.img=i;
    }

    void show(){
        System.out.println(+real+"+"+img+"i");
    }

    public static complex add(complex n1, complex n2){
        complex add=new complex(0,0);
        add.real=n1.real+n2.real;
        add.img= n1.img+n2.img;
        return (add);
    }

    public static complex sub(complex n1, complex n2){
        complex sub= new complex(0,0);
        sub.real= n1.real-n2.real;
        sub.img=n1.img-n2.img;
        return (sub);
    }

    public static complex div(complex n1, complex n2){
        complex div= new complex(0,0);
        div.real= n1.real/n2.real;
        div.img=n1.img/n2.img;
        return (div);
    }


    public static complex mul(complex n1, complex n2){
        complex mul= new complex(0,0);
        mul.real= n1.real*n2.real;
        mul.img=n1.img*n2.img;
        return (mul);
    }

    public static void main (String args[]){
        complex c1=new complex(4,5);
        complex c2=new complex(3,6);
        System.out.println("Enter complex numbers 1 is");
        c1.show();
        System.out.println("Enter complex numbers 2 is");
        c2.show();
        complex add=add(c1,c2);
        System.out.println("Addition of the complex numbers is");
        add.show();
        complex sub=sub (c1,c1);
        System.out.println("Subtraction of the complex numbers is");
        sub.show();
        complex div=div (c1,c2);
        System.out.println("division of the complex numbers is");
        div.show();
        complex mul=mul (c1,c2);
        System.out.println("multiplication of the complex numbers is");
        mul.show();
    }

}
