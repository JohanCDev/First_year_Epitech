import { StatusBar } from 'expo-status-bar';
import React, { Image } from 'react';
import { Text, TextInput, View, TouchableHighlight, TouchableOpacity, FlatList } from 'react-native';
import { back, texts, buttons, views, images } from './styles'
import Icon from 'react-native-vector-icons/FontAwesome'

import firebase from 'firebase'
import "firebase/firestore"

import ProfilePicture from 'react-native-profile-picture'
import { renderItem } from './home_page'

export default class myProfilePage extends React.Component {
    render() {
        return (
            <View style={{ flex: 1, backgroundColor: 'yellow' }}>
                <View style={views.top_bar}>
                    <View style={{ flex: 2, alignItems: 'center', justifyContent: 'center', paddingTop: 25 }}>
                        <Text style={texts.pseudo}>{firebase.auth().currentUser.displayName}</Text>
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center', paddingTop: 35 }}>
                        <Icon name="sliders" size={40} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Params')} />
                    </View>
                </View>

                <View style={views.profil_container}>
                    <View style={{ flex: 7, backgroundColor: '#E8EEF2' }}>
                        <View style={{ flex: 1, alignItems: 'center', justifyContent: 'space-around', paddingTop: 1, flexDirection: 'row' }}>
                            <ProfilePicture
                                isPicture={true}
                                URLPicture={firebase.auth().currentUser.photoURL}
                                shape='circle'
                                width={75}
                                height={75}
                            />
                            <Text style={texts.profil_text}>78{"\n"}Abonnés</Text>
                            <Text style={texts.profil_text}>23{"\n"}Abonnements</Text>
                        </View>
                        <View style={{ flex: 1, alignItems: 'center', justifyContent: 'space-around' }}>
                            <Text style={texts.profil_text}>Vous êtes actuellement sur votre profil, sur une application développée par des Watis-BG </Text>
                            <TouchableOpacity style={{ backgroundColor: '#E8EEF2', borderColor: '#000000', borderWidth: 1, borderRadius: 15 }} onPress={() => { }}>
                                <Text style={texts.profil_text}> Modifier le profil </Text>
                            </TouchableOpacity>
                        </View>
                    </View>
                    <View style={{ flex: 9, backgroundColor: '#E8EEF2' }}>
                        <FlatList
                            data={data}
                            keyExtractor={(item) => item.id.toString()}
                            renderItem={renderItem}
                        />
                    </View>
                </View>

                <View style={views.bottom_bar}>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="home" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Home')} />
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="plus" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Home')} />
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="bookmark" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Home')} />
                    </View>
                </View>
                <StatusBar style="auto" />

            </View>
        )
    }
}