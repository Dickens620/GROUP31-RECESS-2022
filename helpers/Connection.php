<?php
class Connection{
    protected $host = 'localhost';
    protected $user = 'root';
    protected $password = '';
    protected $database = 'kcpms';
    protected $con;

    public function __construct()
    {
        $this->con = mysqli_connect($this->host,$this->user,$this->password,$this->database);  
        print_r(error_get_last());      
    }
    public function select($tableName,$fields=[],$whereCondition=[]){

    }
    public function update($tableName,$whereCondition=[]){

    }
    public function getConnection(){
        return $this->con;
    }

}