<?php
include_once '../helpers/Auth.php';
include_once '../helpers/Connection.php';
session_start();
$auth = new Auth();
if (!$auth->isUserLoggedIn()) {
    echo "You need to login to access this page";
    die();
}
if(!isset($_GET['id'])){
    echo "<h1>Aaaah! What happened</h1> <p>You made a wrong request</p>";
    die();
}
$message = '';
if (isset($_POST['endTime'])) {
    $assignment = $_POST['assignment'];

    $assignmentDate = $_POST['assignmentDate'];
    $startDate = $_POST['startDate'];
    $startTime = $_POST['startTime'];
    $endDate = $_POST['endDate'];
    $endTime = $_POST['endTime'];

    $db = new Connection();
    $data = array(
    'assignment'=>$assignment,
    'startDate'=>$startDate,
    'startTime'=>$startTime,
    'endDate'=>$endDate,
    'endTime'=>$endTime    
    );
    // print_r($data);
    $ret =  $db->insert("assignments", $data);
    if (is_numeric($ret)) {
        // Redirect to view pupils
        header("Location: ../assignments/view_assignments.php");
        die();
    } else {
        $message = "Error occured, Reason: $ret";
    }
}
$connection = new Connection();
$assignment = $connection->select('assignments',[],['id'=>$_GET['id']])[0];
// Check if assignment has already started
if(date("Y-m-d",time())>$assignment['startDate']){
    ?>
        <h1 style="text-align: center;">Sorry! You can't edit this assignment</h1>
        <p style="text-align: center;">Redirecting in <span id="msg"></span></p>
        <script>
            var msg = document.getElementById('msg');
            var counter = 3;
            msg.innerText = counter+ " seconds";
            
            setInterval(()=>{
                counter--;
                if(counter==1){
                    msg.innerText = counter + " second";
           
                }
                else{
                    msg.innerText = counter + " seconds";
           
                }
                 },1000)
            setTimeout(()=>{
                window.location = './view_assignments.php'
            },3000)

        </script>
    <?php
    die();

}
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
    <meta name="description" content="" />
    <meta name="author" content="" />
    <title>ADD ASSIGNMENT</title>
    <link href="https://cdn.jsdelivr.net/npm/simple-datatables@latest/dist/style.css" rel="stylesheet" />
    <link href="../css/styles.css" rel="stylesheet" />
    <script src="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/js/all.min.js" crossorigin="anonymous"></script>
</head>

<body class="sb-nav-fixed">
    <?php
    include('../navbar.php');
    ?>

    <div id="layoutSidenav">
        <?php
        include '../sidebar.php';
        ?>
        <div id="layoutSidenav_content">
            <main>

                <div class="container">
                    <div class="row justify-content-center">
                        <div class="col-lg-7">
                            <div class="card shadow-lg border-0 rounded-lg mt-5">
                                <div class="card-header">
                                    <h3 class="text-center font-weight-light my-4">Assignment Details</h3>
                                    <h3>
                                        <small><?= $message ?></small>
                                    </h3>
                                </div>
                                <div class="card-body">
                                    <form method="POST" action="./edit_assignment.php?id=<?=$assignment['id']?>">
                                        <div class="row mb-3">
                                            <div class="form-floating mb-3">
                                                <input class="form-control" maxlength="8"  required id="inputAssignemnt" name="assignment" type="phonenumber" placeholder="assignment ID" value="<?=$assignment['assignment']?>" />
                                                <label for="assignment">Assignment</label>
                                            </div>
                                            <br>
                                            <p>Start </p>
                                            <div class="col-md-6">
                                                <div class="form-floating mb-3 mb-md-0">
                                                    <input required type="date" pattern="YYYY-MM-DD" type="date" value="<?=$assignment['startDate']?>" class="form-control" id="startDate" name="startDate" />
                                                    <label for="startDate">Start Date</label>
                                                </div>
                                            </div>
                                            <div class="col-md-6">
                                                <div class="form-floating">
                                                    <input required class="form-control" id="startTime" name="startTime" value="<?=$assignment['startTime']?>" type="time" placeholder="Enter the assignment start time" />
                                                    <label for="startTime">Start time</label>
                                                </div>
                                            </div>
                                        </div>
                                        <br>
                                        <div class="row mb-3">
                                            <p>Stop</p>

                                            <div class="col-md-6">
                                                <div class="form-floating mb-3 mb-md-0">
                                                    <input required type="date" class="form-control" id="endDate" name="endDate" value="<?=$assignment['endDate']?>"/>
                                                    <label for="endDate">End Date</label>
                                                </div>
                                            </div>
                                            <div class="col-md-6">
                                                <div class="form-floating mb-3 mb-md-0">
                                                    <input class="form-control" required id="endTime" name="endTime" type="time" value="<?=$assignment['endTime']?>" placeholder="Enter the end time of the assignment" />
                                                    <label for="endTime">End time</label>
                                                </div>
                                            </div>

                                        </div>
                                        <div class="mt-4 mb-0">
                                            <div class="d-grid">
                                                <input class="btn btn-primary btn-block" type="submit" value="Issue Assignment">
                                            </div>
                                        </div>
                                    </form>
                                </div>

                            </div>
                        </div>
                    </div>
                </div>

            </main>
            <footer class="py-4 bg-light mt-auto">
                <div class="container-fluid px-4">

                <button class="btn btn-success mt-2 mb-1"  onclick="window.location='view_assignments.php'"> Back</button>
                    <div class="d-flex align-items-center justify-content-between small">
                        <div class="text-muted">GROUP 31 RECESS 2022</div>
                        <div>
                            <a href="#">Pupil system</a> &middot;
                            <a href="#">KCPMS</a>
                        </div>
                    </div>
                </div>
            </footer>
        </div>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" crossorigin="anonymous"></script>
    <script src="../js/scripts.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.8.0/Chart.min.js" crossorigin="anonymous"></script>
    <script src="../assets/demo/chart-area-demo.js"></script>
    <script src="../assets/demo/chart-bar-demo.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/simple-datatables@latest" crossorigin="anonymous"></script>
    <script src="../js/datatables-simple-demo.js"></script>
</body>

</html>
