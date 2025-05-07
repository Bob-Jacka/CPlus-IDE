#pragma once
#include <QtWidgets>
#include "ExternalVariable.h"
#include "UtilFuncs.hpp"

/*
 * Controller that assocciated with file system actions
 */
class FileController {
private:
    const string log_def_name = "data";
    const string log_file_ext = ".log";
    const string cp_file_ext = ".cx";

public:
    static void init_file_explorer() const;
    static void open_file(const string &file_name) const;
    static void close_file(const string &file_name) const;

    void create_log_file() const;

    FileController() {}
    ~FileController() {}
};

/*
 *Method for initializing file exporer window
 */
void FileController::init_file_explorer() const
{
    QFileSystemModel *model = new QFileSystemModel();
    QTreeView *treeView = new QTreeView();
    model->setRootPath(QDir::rootPath());
    treeView->setModel(model);
    treeView->show();
}

/*
 *Method for opening file
 */
void FileController::open_file(const string &file_name) const
{
    try {
        ifstream *file(file_name);
        logger->log_message("File opened");
    } catch (exception &e) {
        logger->log_error("Error ocurred in opening file");
    }
}

/*
 *Method for closing file
 */
void FileController::close_file(const string &file_name) const
{
    try {
        logger->log_message("File closed");
    } catch (exception &e) {
        logger->log_error("Error ocurred in closing file");
    }
    println("File closed");
}

/*
 * Method for creating log file.
 */
void FileController::create_log_file() const
{
    try {
        ifstream *log_file(log_def_name + log_file_ext);
        logger->log_message("Log File created");
    } catch (exception &e) {
        logger->log_error("Error ocurred in creating log file");
    }
}
