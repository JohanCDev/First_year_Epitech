import 'react-native-gesture-handler';
import { StatusBar } from 'expo-status-bar';
import React from 'react';
import { useFonts } from 'expo-font';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import AppLoading from "expo-app-loading";
import MyConnexion from './components/connexion'
import MyHomePage from './components/home_page'
import myProfilePage from './components/profile_page';
import MyDmPage from './components/direct_message';
import MyAddPage from './components/add_post'
import MyParams from './components/params';

import myRegisterScreen from './components/auth/register';
import * as firebase from 'firebase'

const Stack = createStackNavigator();

const firebaseConfig = {
  apiKey: "AIzaSyBNOLAFcYT7T2ASOBDImlF-BkAu9xoKCSY",
  authDomain: "garassi-9ad52.firebaseapp.com",
  projectId: "garassi-9ad52",
  storageBucket: "garassi-9ad52.appspot.com",
  messagingSenderId: "230869586450",
  appId: "1:230869586450:web:e4e6dd615a816ed86fbecb",
  measurementId: "G-LVVXJ5E37Z"
};

if (firebase.apps.length === 0) {
  firebase.initializeApp(firebaseConfig)
}

export default function App() {
  let [fontsLoaded] = useFonts({
    'Onyx': require('./assets/fonts/Onyx.ttf'),
    'lucida-sans-normal': require('./assets/fonts/LucidaSans/LucidaSans-Normal.ttf'),
    'lucida-sans-italic': require('./assets/fonts/LucidaSans/LucidaSans-Italic.ttf'),
  });
  if (!fontsLoaded)
    return (<AppLoading />)
  return (
    <NavigationContainer>
      <Stack.Navigator screenOptions={{ headerShown: false }}>
        <Stack.Screen name="Connexion" component={MyConnexion} />
        <Stack.Screen name="register" component={myRegisterScreen} />
        <Stack.Screen name="Home" component={MyHomePage} />
        <Stack.Screen name="Profile" component={myProfilePage} />
        <Stack.Screen name="Dm" component={MyDmPage} />
        <Stack.Screen name="Add" component={MyAddPage} />
        <Stack.Screen name="Params" component={MyParams} />
      </Stack.Navigator>
    </NavigationContainer>
  )
}
