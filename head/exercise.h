#ifndef EXERCISE_H
#define EXERCISE_H 

#include <string>
#include <vector>
#include <map>

#include "customer.h" // NEW ������� �߰�

using namespace std;

class Exercise {
public:
    int id; // customer ����� ID
    string name;
    string type; // � ����
    int duration; // � �ð�

    // Exercise ��ü�� �����ϴ� ������ �Լ�
    Exercise(int id, string name, string type, int duration)
        : id(id), name(name) ,type(type), duration(duration) {}

    void display() const; // � ��� ������ ����ϴ� ��� �Լ�

    bool operator==(const Exercise& other) const {
        return (type == other.type) && (duration == other.duration);
    }
};

// � ��ϵ��� �����ϴ� ExerciseManager Ŭ����
class ExerciseManager {
private:
    vector<Exercise> exercises; //  ��� � ����� �����ϴ� ����
    map<string, vector<Exercise>> exercisesByType; // � �������� � ����� �����ϴ� �� �����̳�

public:
    void loadFromCSV(const string& filename); // � ��� ������ �ҷ�����
    void saveToCSV(const string& filename); // � ��� ������ ����

    void addExercise(const Customer& cust,const string& type, int duration); // � ��� �߰� NEW ����
    void modifyExercise(int id, const string& type,int duration); // � ��� ���� NEW index->id �� ����
    void deleteExercise(int id); // � ��� ���� NEW index->id �� ����

    void displayExercises() const; // � ��� ���
    const vector<Exercise>& getExercisesByType(const string& type) const; // Ư�� � ������ �ش��ϴ� � ��ϵ��� ��ȯ�ϴ� ��� �Լ�
};

#endif 