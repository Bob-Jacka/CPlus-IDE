#pragma once
#include <QtWidgets>
#include "UtilFuncs.hpp"

class FileController {
private:
    //

public:
    static void init_file_explorer();
    static void open_file(const string &file_name);
    static void close_file(const string &file_name);

    FileController() {}
    ~FileController() {}
};

/*
 *Method for initializing file exporer window
 */
void FileController::init_file_explorer() {
    QFileSystemModel *model = new QFileSystemModel();
    QTreeView *treeView = new QTreeView();
    model->setRootPath(QDir::rootPath());
    treeView->setModel(model);
    treeView->show();
}

/*
 *Method for opening file
 */
void FileController::open_file(const string &file_name) {
    println("File opened");
}

/*
 *Method for closing file
 */
void FileController::close_file(const string &file_name) {
    println("File closed");
}
