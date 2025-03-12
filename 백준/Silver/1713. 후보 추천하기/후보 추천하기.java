import java.util.*;

public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();


        Student students[] = new Student[101];
        for (int i = 1; i <= 100; i++) {
            students[i] = new Student(i,0, false, -1);
        }


        LinkedList<Student> pictures = new LinkedList<>();

        int studentNums = sc.nextInt();
        for (int i = 0; i<studentNums; i++) {
            int tmp = sc.nextInt();
            if(students[tmp].posted){
                students[tmp].recommend++;
            }
            else{
                if(pictures.size() < n){
                    students[tmp].posted = true;
                    students[tmp].recommend = 1;
                    students[tmp].time = i;
                    pictures.add(students[tmp]);
                }else{
                    Collections.sort(pictures,new Comparator<Student>() {
                        public int compare(Student s1, Student s2) {
                            if(s1.recommend == s2.recommend){
                                return s1.time - s2.time;
                            }
                            return s1.recommend - s2.recommend;
                        }
                    });
                    Student remove = pictures.get(0);
                    remove.posted = false;
                    remove.recommend = 0;
                    pictures.remove(0);
                    students[tmp].posted = true;
                    students[tmp].recommend = 1;
                    students[tmp].time = i;
                    pictures.add(students[tmp]);

                }
            }

        }
        Collections.sort(pictures,(s1,s2) -> s1.num - s2.num);
        for (Student student : pictures) {
            System.out.print(student.num+" ");
        }

    }

    static class Student {
        int num;
        int recommend;
        boolean posted;
        int time;
        public Student(int num,int recommend, boolean posted, int time) {
            this.num = num;
            this.recommend = recommend;
            this.posted = posted;
            this.time = time;
        }
    }
}