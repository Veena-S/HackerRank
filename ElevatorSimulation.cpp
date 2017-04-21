// ElevatorSimulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

struct PASSANGER
{
    bool bIsTeacher;
    bool bIsAddedForTrip ;
    int time;
    int floor;

    PASSANGER() : bIsTeacher( false ), bIsAddedForTrip( false ){}
};

int main()
{
    int nPeople;
    int wait;
    int capacity;
    int mPos;
    cin >> nPeople >> wait >> capacity >> mPos;

    if( nPeople < 1 || nPeople > 100 || mPos < 1 || mPos > nPeople ||
        wait < 1 || wait > 500 || capacity < 1 || capacity > 25 )
    {
        return 0;
    }

    vector<PASSANGER> TotalPassengerVector;
    vector<PASSANGER> StudentVector;
    vector<PASSANGER> TeacherVector;
    bool bIsRoryTravelling = false;

    for(int a0 = 0; a0 < nPeople; a0++)
    {
        PASSANGER stPass;
        int id;
        cin >> id >> stPass.time >> stPass.floor;

        if( id < 1 || id > 2 || stPass.time < 1 || stPass.time > 500 ||
            stPass.floor < 1 || stPass.floor > 25 )
        {
            return 0;
        }
        if( id == 1 )
        {
            stPass.bIsTeacher = false;
            //            StudentPassengerIndexVctr.push_back( a0 );
            StudentVector.push_back( stPass );
        }
        else
        {
            stPass.bIsTeacher = true;
            TeacherVector.push_back( stPass );
        }
        stPass.bIsTeacher = ( id == 1 ) ? false : true;
        TotalPassengerVector.push_back( stPass );
    }

    vector<PASSANGER> ElevatorVector;
    int nTravalledPassengers = 0;
    int nTripCount = 0;
    int nLastPersonDropTime = 0;
    int nRorysTrip = 0;

    while( nTravalledPassengers <= nPeople )
    {
        // First fill the elevator with the teachers, if they are eligible.
        for( int ti = 0; ti < TeacherVector.size(); ti++ )
        {

        }
    }




    ElevatorVector.push_back( TotalPassVector[0] );
    // Departure time:
    int departure = TotalPassVector[0].time + wait;
    int nElevatorCount = ElevatorVector.size();
    //    int nTotalPassengers = nPeople;
    if( !TotalPassVector[0].bIsTeacher )
    {
        StudentElevatorIndexVector.push_back( 0 );
    }
    

    int nStartIndex = 1;
    int nPersonsTravelled = 0;
    int nFirstSkippedIndex = -1;
    int i = nStartIndex;
    //   while( nPersonsTravelled < nPeople )
    {
        // for( int i = nStartIndex; i < TotalPassVector.size(); i++ )
        while( i < TotalPassVector.size())
        {
            if( nElevatorCount == capacity ) // Starts the trip
            {
                // Capacity has reached.
                nTripCount++;

                // But check whether the queue has a teacher under waiting at a time
                // less than or equal to this departure timing.
                // First check for the time of next item. If it falls the departure constraint, check for
                // teacher.
                int nTemp = i;
                while( nTemp < TotalPassVector.size())
                {
                    if( TotalPassVector[nTemp].time <= departure )
                    {
                        if( TotalPassVector[nTemp].bIsTeacher  && !TotalPassVector[nTemp].bIsAddedForTrip )
                        {
                            // Remove the last entered Student and enter the teacher.
                            int nStudentElevatorIndexVectorSize = StudentElevatorIndexVector.size();
                            if( nStudentElevatorIndexVectorSize >= 0 )
                            {
                                // Identify the location at which the student needs to be entered.
                                // It should enter at the location that is less than or equal to this
                                // departure time.
                                // Check which is the item with next higher time than the current departure time.
                                int nLastIdx = nTemp + 1;
                                int nIdxLastStudentElevator = 
                                    StudentElevatorIndexVector[ nStudentElevatorIndexVectorSize - 1];
                                while( nLastIdx < TotalPassVector.size() )
                                {
                                    if( TotalPassVector[nLastIdx].time > departure )
                                    {
                                        // Insert the student here.
                                        TotalPassVector.insert( TotalPassVector.begin() + nLastIdx,
                                            TotalPassVector[nIdxLastStudentElevator] );
                                        bIsRoryTravelling = ( mPos == nIdxLastStudentElevator ) ? false : true;
                                        // Remove that entry from the elevator.
                                        ElevatorVector.erase( ElevatorVector.begin() + nStudentElevatorIndexVectorSize - 1 );
                                        StudentElevatorIndexVector.erase( StudentElevatorIndexVector.begin() +
                                            nStudentElevatorIndexVectorSize );
                                        nStudentElevatorIndexVectorSize--;
                                        break;
                                    }
                                    nLastIdx++;
                                }
                                // Add the teacher to the elevator.
                                ElevatorVector.push_back( TotalPassVector[nTemp] );
                                TotalPassVector[nTemp].bIsAddedForTrip = true;
                            }
                            //                         else
                            //                         {
                            //                             // There are no students in the elevator as of now. Teacher has to wait.
                            //                         }
                        }
                    }
                    else // No need to consider the passengers coming after the departure of elevator.
                    {
                        break;
                    }
                    nTemp++;
                }

                // Start the trip.
                int nMaxFloor = 0;
                int nEleSize = ElevatorVector.size();
                for( int f = 0; f < nEleSize; f++ )
                {
                    nMaxFloor = ( ElevatorVector[f].floor > nMaxFloor ) ? ElevatorVector[f].floor : nMaxFloor;
                }
                nLastPersonDropTime = departure + ElevatorVector[nEleSize - 1].floor;
                nRorysTrip = ( bIsRoryTravelling ) ? nTripCount : -1;
                nPersonsTravelled += nEleSize;
                ElevatorVector.clear();
                StudentElevatorIndexVector.clear();
                nFirstSkippedIndex = -1;
            }
            else // Not up to the capacity.
            {
                int nTemp = i;
                while( nTemp < TotalPassVector.size() && ElevatorVector.size() < capacity )
                {
                    // Consider the teachers first.
                    PASSANGER pass = TotalPassVector[nTemp];
                    if( pass.time <= departure && !pass.bIsAddedForTrip )
                    {
                        if( pass.bIsTeacher )
                        {
                            ElevatorVector.push_back( pass );
                            TotalPassVector[nTemp].bIsAddedForTrip = true;
                        }
                        else // skipping it
                        {
                            if( !pass.bIsAddedForTrip && nFirstSkippedIndex == -1 )
                            {
                                nFirstSkippedIndex = nTemp;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                    nTemp++;
                }
                PASSANGER pass = TotalPassVector[i];

                if( ( pass.time <= departure ) && ( !pass.bIsTeacher ) &&
                    ( ElevatorVector.size() < capacity ) && !pass.bIsAddedForTrip )
                {
                    ElevatorVector.push_back( pass );
                    StudentElevatorIndexVector.push_back( i );
                    bIsRoryTravelling = ( i == mPos ) ? true : false;
                    TotalPassVector[i].bIsAddedForTrip = true;
                }
            }
            nElevatorCount = ElevatorVector.size();
            i++;
            if(( nFirstSkippedIndex < i ) && ( nFirstSkippedIndex != -1 ))
            {
                i = nFirstSkippedIndex;
            }
        }
    }

    cout << nRorysTrip << " " << nLastPersonDropTime;

    return 0;
}





//// ElevatorSimulation.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct PASSANGER
//{
//    bool bIsTeacher;
//    bool bIsAddedForTrip ;
//    int time;
//    int floor;
//
//    PASSANGER() : bIsTeacher( false ), bIsAddedForTrip( false ){}
//};
//
//int main()
//{
//    int nPeople;
//    int wait;
//    int capacity;
//    int mPos;
//    cin >> nPeople >> wait >> capacity >> mPos;
//
//    if( nPeople < 1 || nPeople > 100 || mPos < 1 || mPos > nPeople ||
//        wait < 1 || wait > 500 || capacity < 1 || capacity > 25 )
//    {
//        return 0;
//    }
//
//    vector<PASSANGER> TotalPassVector;
//    // vector<int> StudentPassengerIndexVctr;
//    vector<int> StudentElevatorIndexVector;
//    bool bIsRoryTravelling = false;
//    for(int a0 = 0; a0 < nPeople; a0++)
//    {
//        PASSANGER stPass;
//        int id;
//        cin >> id >> stPass.time >> stPass.floor;
//        
//        if( id < 1 || id > 2 || stPass.time < 1 || stPass.time > 500 ||
//            stPass.floor < 1 || stPass.floor > 25 )
//        {
//            return 0;
//        }
//        if( id == 1 )
//        {
//            stPass.bIsTeacher = false;
////            StudentPassengerIndexVctr.push_back( a0 );
//        }
//        else
//        {
//            stPass.bIsTeacher = true;
//        }
//        stPass.bIsTeacher = ( id == 1 ) ? false : true;
//        TotalPassVector.push_back( stPass );
//    }
//
//    
//
//    vector<PASSANGER> ElevatorVector;
//    ElevatorVector.push_back( TotalPassVector[0] );
//    // Departure time:
//    int departure = TotalPassVector[0].time + wait;
//    int nElevatorCount = ElevatorVector.size();
////    int nTotalPassengers = nPeople;
//    if( !TotalPassVector[0].bIsTeacher )
//    {
//        StudentElevatorIndexVector.push_back( 0 );
//    }
//    int nTripCount = 0;
//    int nLastPersonDropTime = 0;
//    int nRorysTrip = 0;
//
//    int nStartIndex = 1;
//    int nPersonsTravelled = 0;
//    int nFirstSkippedIndex = -1;
//    int i = nStartIndex;
// //   while( nPersonsTravelled < nPeople )
//    {
//        // for( int i = nStartIndex; i < TotalPassVector.size(); i++ )
//        while( i < TotalPassVector.size())
//        {
//            if( nElevatorCount == capacity ) // Starts the trip
//            {
//                // Capacity has reached.
//                nTripCount++;
//
//                // But check whether the queue has a teacher under waiting at a time
//                // less than or equal to this departure timing.
//                // First check for the time of next item. If it falls the departure constraint, check for
//                // teacher.
//                int nTemp = i;
//                while( nTemp < TotalPassVector.size())
//                {
//                    if( TotalPassVector[nTemp].time <= departure )
//                    {
//                        if( TotalPassVector[nTemp].bIsTeacher  && !TotalPassVector[nTemp].bIsAddedForTrip )
//                        {
//                            // Remove the last entered Student and enter the teacher.
//                            int nStudentElevatorIndexVectorSize = StudentElevatorIndexVector.size();
//                            if( nStudentElevatorIndexVectorSize >= 0 )
//                            {
//                                // Identify the location at which the student needs to be entered.
//                                // It should enter at the location that is less than or equal to this
//                                // departure time.
//                                // Check which is the item with next higher time than the current departure time.
//                                int nLastIdx = nTemp + 1;
//                                int nIdxLastStudentElevator = 
//                                    StudentElevatorIndexVector[ nStudentElevatorIndexVectorSize - 1];
//                                while( nLastIdx < TotalPassVector.size() )
//                                {
//                                    if( TotalPassVector[nLastIdx].time > departure )
//                                    {
//                                        // Insert the student here.
//                                        TotalPassVector.insert( TotalPassVector.begin() + nLastIdx,
//                                            TotalPassVector[nIdxLastStudentElevator] );
//                                        bIsRoryTravelling = ( mPos == nIdxLastStudentElevator ) ? false : true;
//                                        // Remove that entry from the elevator.
//                                        ElevatorVector.erase( ElevatorVector.begin() + nStudentElevatorIndexVectorSize - 1 );
//                                        StudentElevatorIndexVector.erase( StudentElevatorIndexVector.begin() +
//                                            nStudentElevatorIndexVectorSize );
//                                        nStudentElevatorIndexVectorSize--;
//                                        break;
//                                    }
//                                    nLastIdx++;
//                                }
//                                // Add the teacher to the elevator.
//                                ElevatorVector.push_back( TotalPassVector[nTemp] );
//                                TotalPassVector[nTemp].bIsAddedForTrip = true;
//                            }
////                         else
////                         {
////                             // There are no students in the elevator as of now. Teacher has to wait.
////                         }
//                        }
//                    }
//                    else // No need to consider the passengers coming after the departure of elevator.
//                    {
//                        break;
//                    }
//                    nTemp++;
//                }
//
//                // Start the trip.
//                int nMaxFloor = 0;
//                int nEleSize = ElevatorVector.size();
//                for( int f = 0; f < nEleSize; f++ )
//                {
//                    nMaxFloor = ( ElevatorVector[f].floor > nMaxFloor ) ? ElevatorVector[f].floor : nMaxFloor;
//                }
//                nLastPersonDropTime = departure + ElevatorVector[nEleSize - 1].floor;
//                nRorysTrip = ( bIsRoryTravelling ) ? nTripCount : -1;
//                nPersonsTravelled += nEleSize;
//                ElevatorVector.clear();
//                StudentElevatorIndexVector.clear();
//                nFirstSkippedIndex = -1;
//            }
//            else // Not up to the capacity.
//            {
//                int nTemp = i;
//                while( nTemp < TotalPassVector.size() && ElevatorVector.size() < capacity )
//                {
//                    // Consider the teachers first.
//                    PASSANGER pass = TotalPassVector[nTemp];
//                    if( pass.time <= departure && !pass.bIsAddedForTrip )
//                    {
//                        if( pass.bIsTeacher )
//                        {
//                            ElevatorVector.push_back( pass );
//                            TotalPassVector[nTemp].bIsAddedForTrip = true;
//                        }
//                        else // skipping it
//                        {
//                            if( !pass.bIsAddedForTrip && nFirstSkippedIndex == -1 )
//                            {
//                                nFirstSkippedIndex = nTemp;
//                            }
//                        }
//                    }
//                    else
//                    {
//                        break;
//                    }
//                    nTemp++;
//                }
//                PASSANGER pass = TotalPassVector[i];
//
//                if( ( pass.time <= departure ) && ( !pass.bIsTeacher ) &&
//                    ( ElevatorVector.size() < capacity ) && !pass.bIsAddedForTrip )
//                {
//                    ElevatorVector.push_back( pass );
//                    StudentElevatorIndexVector.push_back( i );
//                    bIsRoryTravelling = ( i == mPos ) ? true : false;
//                    TotalPassVector[i].bIsAddedForTrip = true;
//                }
//            }
//            nElevatorCount = ElevatorVector.size();
//            i++;
//            if(( nFirstSkippedIndex < i ) && ( nFirstSkippedIndex != -1 ))
//            {
//                i = nFirstSkippedIndex;
//            }
//        }
//    }
//
//    cout << nRorysTrip << " " << nLastPersonDropTime;
//
//    return 0;
//}
//
