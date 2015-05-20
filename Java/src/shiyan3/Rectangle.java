package shiyan3;
public class Rectangle{
    private double width;
    private double height;
    public void setWidth(double var){
        width=var;
    } 
    public void setHeight(double var){
        height=var;
    } 
    public double getArea(){
        return width*height;
    }
    public double getPerimeter(){
        return (width+height)*2;
    }
    public double getWidth(){
        return width;
    }
    public double getHeight(){
        return height;
    }
    public Rectangle(){
        width=height=1d;
    } 
    public Rectangle(double width,double height){
        this.width=width;
        this.height=height;
    }
    public void print(){
        System.out.println("宽为："+width+" 高为："+height+
                " 面积为："+getArea()+" 周长为："+getPerimeter());
    }
    public static void main(String[]args){
        Rectangle a = new Rectangle(4,40);
        Rectangle b = new Rectangle(3.5,35.9);
        System.out.print("矩形a的");
        a.print();
        System.out.print("矩形b的");
        b.print();
    } 
}
