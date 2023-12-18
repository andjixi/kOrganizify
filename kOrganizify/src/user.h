#ifndef USER_H
#define USER_H

#include "saveload.h"
#include "calendar.h"
#include "toDoList.h"
#include "settings.h"

#include <QString>
#include <QFile>
#include <QJsonValue>

class User : public SaveLoad
{

public:
    explicit User(const QString &username, const QString &password);
    bool userExists(const QString &username);
    void loadData(const QString &username);
    void saveData(const QString &username);
    QJsonValue toJson() const override;
    void fromJson(const QJsonObject &jsonValue) override;

    bool login(const QString &password);
    bool registerUser(const QString &password);
    void logout();

    // // Getters
    // Calendar getCalendar() const;
    // ToDoList getToDoList() const;
    // Settings getSettings() const;
    // // Setters
    // void setCalendar(const Calendar &calendar);
    // void setToDoList(const ToDoList &toDoList);
    // void setSettings(const Settings &settings);


private:
    QString m_username;
    QString m_password;
    Calendar m_calendar;
    ToDoList m_toDoList;
    Settings m_settings;


    // void updateUserData(const QJsonObject &userData);

};

#endif // USER_H
